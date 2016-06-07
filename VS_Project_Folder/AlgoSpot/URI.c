#include <stdio.h>
#include <stdlib.h>

struct encode_table{
	char special_char;
	int hex_code;
};

struct encode_table table[7]= {
		{ ' ', 0x20 },
		{ '!', 0x21 },
		{ '$', 0x24 },
		{ '%', 0x25 },
		{ '(', 0x28 },
		{ ')', 0x29 },
		{ '*', 0x2a }
};

char search_table(int hex_code)
{
	char ch;
	int i; 

	for (i = 0; i < 7; i++)
	{
		if (table[i].hex_code == hex_code)
		{
			ch = table[i].special_char;
			return ch;
		}
	}

	return -1;
}

void decode_percent_encoding(char * out, char * in)
{
	int j = 0; // j is out str's index
	char * ch = in;
	char decoded_char;
	int hex_code;

	while (*ch != '\0')
	{
		if (*ch == '%')
		{
			hex_code = (*(++ch) - '0') * 16;
			if (*(++ch) == 'a')
				hex_code += 10;
			else
				hex_code += (*ch - '0');

			decoded_char = search_table(hex_code);
			if (decoded_char == -1){
				fprintf(stdout, "search failed\n");
				return;
			}

			out[j] = decoded_char;
		}
		else
			out[j] = *ch;

		j++;
		ch++;
	}

	out[j] = '\0';
}


int main()
{
	int C, i;
	char input_buf[81] = { '\0', };
	char output_buf[81] = { '\0', };

	fscanf(stdin, "%d", &C);
	
	
	for (i = 0; i < C; i++)
	{
		fscanf(stdin, "%s", input_buf);
		decode_percent_encoding(output_buf, input_buf);
		fprintf(stdout, "%s\n", output_buf);
	}


	return 0;
}