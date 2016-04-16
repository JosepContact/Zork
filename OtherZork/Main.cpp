#include <stdio.h>
#include "MemLeaks.h"
#include "World.h"
#include "DynArray.h"

	int main(void){
		ReportMemoryLeaks();
		/*char action[30], *fp = action;
		fgets(action, 30, stdin);
		String input(fp);
		Vector<String> patatacaliente;
		patatacaliente = input.Tokenize(patatacaliente);

		if (patatacaliente[0] == "perras") printf("hola putas");
		if (patatacaliente[1] == "infernales") printf("hola putas");
		
		*/
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