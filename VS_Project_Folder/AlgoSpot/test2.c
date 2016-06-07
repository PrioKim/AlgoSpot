#include <stdio.h>
#include <math.h>

#define CPU			8		// 8 core
#define MEM			16		// 16 GB
#define VM_COUNT	4
#define VM_LIMIT	(((CPU) <= (MEM)) ? (CPU) : (MEM))
#define AGING_CONST	0.9f


int main()
{
	int total_resource = 16; //t
	float reasonable_usage = 0.7f; //s
	int consumed_resource_all_VM = 0; // c

	//int consumed_resource_each_vm[10] = { 0 };//V
	int consumed_resource_each_vm[30] = { 2, 2, 6, 6, 0 };//V
	//int demand_of_vm[10] = { 2,8,8,6,0 }; // D
	int demand_of_vm[30] = { 4, 7, 8, 3, 0 }; // D
	float weighted_vector[30] = { 0.5f, 0.8f, 0.3f, 0.4f, 0 };//W
	float want_assign_resource[30] = { 0, }; //A

	float usage_each_vm[30] = { 0.9f, 0.9f, 0.99f, 0.99f, 0 };//U

	int remain_vm_cnt = VM_COUNT;
	int aging_for_vm_cnt = VM_COUNT;
	int i = 0, j = 0;
	float vector_sum = 0.0, assign_sum = 0;

	float aging_demand_cont = 0.9f;
	float aging_aging = 0.9f;



	for (i = 0; i < VM_COUNT; i++)
	{
		vector_sum += weighted_vector[i];
	}

	for (i = 0; i < VM_COUNT; i++)
	{
		want_assign_resource[i] = (weighted_vector[i] / vector_sum) * total_resource; // �ʹ� ���Ϳ� ���� �Ҵ��... ���� ���ڿ��� �����ſ���

		//demand_of_vm[i] = ceil((usage_each_vm[i] * consumed_resource_each_vm[i]) / reasonable_usage);
	}


	if (VM_COUNT == VM_LIMIT)
	{
		printf("VM���� �ִ� ���� ������ �ּ� ���ҽ��� �й�\n");
		return 0;
	}

	while (remain_vm_cnt > 0)
	{
		j++;


		assign_sum = 0;
		for (i = 0; i < VM_COUNT; i++)
			assign_sum += want_assign_resource[i];

		fprintf(stdout, "-----------------------------------\n");
		fprintf(stdout, "while loop[%d]\n", j);
		fprintf(stdout, "%20s", "a_i(assign_avail) : ");

		for (i = 0; i < VM_COUNT; i++)
		{
			want_assign_resource[i] =
				(want_assign_resource[i] / assign_sum) * (total_resource - consumed_resource_all_VM);
			fprintf(stdout, "%f ", want_assign_resource[i]);
		}

		fprintf(stdout, "\n");
		fprintf(stdout, "%20s", "d_i(demand) : ");
		for (i = 0; i < VM_COUNT; i++)
			fprintf(stdout, "%d ", demand_of_vm[i]);

		fprintf(stdout, "\n%10s assigned_resource : ");
		for (i = 0; i < VM_COUNT; i++)
			fprintf(stdout, "%d ", consumed_resource_each_vm[i]);

		fprintf(stdout, "\n%17s : %f", "aging constant", aging_demand_cont);
		fprintf(stdout, "\n-----------------------------------");
		fprintf(stdout, "\n\n");


		for (i = 0; i < VM_COUNT; i++) // vm �ϳ��� ó�� �Ǵ���, ���δ� ó���� �ȵǴ���, VM �ϳ��� �ڿ��Ҵ��� �Ǹ� break�ϰ� a_i�� �ٽ� ���
		{
			if (want_assign_resource[i] != 0 && (want_assign_resource[i] >= demand_of_vm[i] || remain_vm_cnt == 1))
				// a_i�� 0�� ���� �Ҵ��� �Ϸ�� ����̴�. a_i�� 0�� �ƴϰ�, (a_i >= d_i�� �� �Ǵ� ���� VM�� �ϳ��ϰ��) �Ҵ��Ѵ�.
			{
				if (want_assign_resource[i] >= demand_of_vm[i]) // �������̾ �����ϰ� �����ȵǰ�
				{
					consumed_resource_each_vm[i] = demand_of_vm[i];
				}
				else // �������� ����ε� ���� �ڿ��� ���ϴ� ��ŭ�� �� ���� ��
				{
					consumed_resource_each_vm[i] = (total_resource - consumed_resource_all_VM);
				}

				consumed_resource_all_VM += consumed_resource_each_vm[i]; // �Ҵ��� �� �ڿ� ����
				want_assign_resource[i] = 0; // �ڿ��� �Ҵ�� VM�� a_i = 0
				remain_vm_cnt--; // �ڿ� �Ҵ�
				break; // a_i���� �ٽ� ��� �ϱ� ���ؼ� break
			}
		}

		//// aging(di) 
		aging_for_vm_cnt--; // 
		if (aging_for_vm_cnt == 0){
			for (i = 0; i < VM_COUNT; i++)
				demand_of_vm[i] = ceil(demand_of_vm[i] * aging_demand_cont);

			aging_demand_cont = aging_demand_cont * aging_demand_cont; //pow(aging_demand_cont, 2); // ���� ��� 2,3�� 0.7�� ���ص� 1.4, 2.1�̹Ƿ� õ���Լ� ���ϸ� �ٽ� 2,3�� �ǹ�����. �׷��� ����¡�� ���ʿ�
			//aging_demand_cont = aging_demand_cont * aging_aging;
			aging_for_vm_cnt = VM_COUNT;
		}
		////
	}

	printf("assigned resources : ");
	for (i = 0; i < VM_COUNT; i++)
	{
		printf("%d ", consumed_resource_each_vm[i]);
	}

	putchar('\n');



	return 0;
}