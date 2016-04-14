#include <stdio.h>
#include "MemLeaks.h"
#include "World.h"
#include "ThisString.h"
#include "DynArray.h"

	int main(void){
		ReportMemoryLeaks();
	/*	char action[30], *fp = action;
		fgets(action, 30, stdin);
		String input(fp);
		Vector<String> patatacaliente;
		patatacaliente = input.Tokenize(patatacaliente);
		*/
		Vector<int> jelou(3);
		jelou.num_elements = 3;
		jelou[0] = 0;
		jelou[1] = 1;
		jelou[2] = 2;
		int x;
		if (jelou.pop_back(x)){
			printf("%d", x);
		}

		World Museum;

		bool game = false;
			Museum.CreateWorld();
		do {
			Museum.currpos();
			game = Museum.Play();
		} while (!game);
		printf("Thanks for playing!\n");
		getchar();

		return 0;

	}