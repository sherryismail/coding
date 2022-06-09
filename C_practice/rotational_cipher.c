	#include <stdio.h>
	// Add any extra import statements you may need here
	#include <stdint.h>
	#include <string.h>
	#include <ctype.h>
	#include <stdlib.h>//malloc
	// Add any helper functions you may need here
	char* rotationalCipher(char input[], int rotationFactor) {
		// Write your code here
	int size = (int)(strlen(input));
	char * output = malloc(size * sizeof(char));
	char x;
	int temp=0, max = 0x7E, min=0x20;
	int i=0;
		while (i<size )
		{
				if(isalnum(input[i]))
				{
					if (islower(input[i])) //a to z is 0x61 to 0x7A
					{
						// 'e' minus 'a' sets the line to [0,25]. Then do +rotFac 
						// the overall num >26, so modulo%26 brings it back to [0,25]
						//finally add the offset of 'a'
						x = (input[i] - 'a' + rotationFactor) % 26 + 'a';
					}
					else if(isupper(input[i]))
					{
						x = (input[i] - 'A' + rotationFactor) % 26 + 'A';
					}
				else //its a number
					{
						x = (input[i] - '0' + rotationFactor) % 10 + '0';
					} 
					output[i] = x;   
				}
			else {
				output[i] = input[i];

			}
			i++;
		}
		return output;
	}
	// These are the tests we use to determine if the solution is correct.
	// You can add your own at the bottom.

	void printCharArray(char arr[]) {
		printf("[\"");
		for (int i = 0; arr[i] != '\0'; i++) {
			printf("%c", arr[i]);
		}
		printf("\"]");
	}

	int test_case_number = 1;

	void check(char expected[], char output[]) {
		int result = !strcmp(expected, output);
		const char* rightTick = u8"\u2713";
		const char* wrongTick = u8"\u2717";
		if (result) {
			printf("%s Test #%d\n", rightTick, test_case_number);
		}
		else {
			printf("%s Test # %d: Expected ", wrongTick, test_case_number);
			printCharArray(expected); 
			printf(" Your output: ");
			printCharArray(output);
			printf("\n");
		}
		test_case_number++;
	}

	int main() {

		char input_1[] = "All-convoYs-9-be:Alert1.";
		int rotationFactor_1 = 4;
		char expected_1[] = "Epp-gsrzsCw-3-fi:Epivx5.";
		char* output_1 = rotationalCipher(input_1, rotationFactor_1);
		check(expected_1, output_1);

		char input_2[] = "abcdZXYzxy-999.@";
		int rotationFactor_2 = 200;
		char expected_2[] = "stuvRPQrpq-999.@";
		char* output_2 = rotationalCipher(input_2, rotationFactor_2);
		check(expected_2, output_2);

		// Add your own test cases here
		  char input_3[] = "Zebra-493";
  int rotationFactor_3 = 3;
  char expected_3[] = "Cheud-726";
  char* output_3 = rotationalCipher(input_3, rotationFactor_3);
  check(expected_3, output_3);
		
	}
	/*One simple way to encrypt a string is to "rotate" every alphanumeric character by a certain amount. 
	Rotating a character means replacing it with another character that is a certain number of steps away 
	in normal alphabetic or numerical order.
	For example, if the string "Zebra-493?" is rotated 3 places, 
	the resulting string is "Cheud-726?". Every alphabetic character 
	is replaced with the character 3 letters higher 
	(wrapping around from Z to A), and every numeric 
	character replaced with the character 3 digits higher 
	(wrapping around from 9 to 0).
	Note that the non-alphanumeric characters remain unchanged.
	*/