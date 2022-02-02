#include <memory>
#include <iostream>

#include "process.hpp"

#define bufferSize 1024

void readFirstLine(char *buffer, FILE *gg);
void readSecondLine(char *buffer, FILE *gg);
void readThirdLine(char *buffer, FILE *gg);
void readFourthLine(char *buffer, FILE *gg);
void readFifthLine(char *buffer, FILE *gg);
void readSixthLine(char *buffer, FILE *gg);
void readSeventhLine(char *buffer, FILE *gg);
void readEighthLine(char *buffer, FILE *gg);

int main(int argc, char** argv)
{ 
	/*std::unique_ptr<procxx::process> processObject;
	processObject = std::unique_ptr<procxx::process>(new procxx::process("./InfilGenerator"));
	processObject->add_argument("./caspoloha.dat0");
	processObject->add_argument("./infil0");
	try
	{
		processObject->exec();
	}
	catch(std::runtime_error &e)
	{
		std::cout << e.what()  << "\n";
		exit(-1);
	}
	if(processObject.get() != nullptr)
	{
		processObject->wait();
	}
	std::string line;
	while (std::getline(processObject->output(), line))
			{
				std::cout<< line << "\n"; 
			}*/
	FILE *gg = fopen("infil0_0", "r");
	if(gg!=NULL)
	{
		char buffer[bufferSize];

		readFirstLine(buffer, gg);
		readSecondLine(buffer, gg);
		readThirdLine(buffer, gg);
		readFourthLine(buffer, gg);
		readFifthLine(buffer, gg);
		readSixthLine(buffer, gg);
		readSeventhLine(buffer, gg);
		readEighthLine(buffer, gg);

		printf("Correct format of infil, for trajectory calculation\n");
		fclose(gg);
	}
	else
	{
		printf("Error opening file infil0_0, terminating\n");
		exit(4);
	}
	return 0;
}

void readFirstLine(char *buffer, FILE *gg){
	if(fgets(buffer,bufferSize,gg) == nullptr){
		std::cout<< "error" << "\n";
	}

	std::cout<< strlen(buffer) << "\n";
	char inputDateStart[50];
	float one;
	float two;
	char smt[50];
	if(sscanf(buffer,"%f %s %f %s\n",&one, inputDateStart, &two, smt)!=3){
		printf("Wrong format of infil first line, for trajectory calculation\n");
		fclose(gg);
		exit(-1);
	}
}

void readSecondLine(char *buffer, FILE *gg){
	if(fgets(buffer,bufferSize,gg) == nullptr){
		std::cout<< "error" << "\n";
	}

	float one;
	float two;
	float three;
	char smt[50];
	if(sscanf(buffer,"%f %f %f %s\n",&one, &three, &two, smt)!=3){
		printf("Wrong format of infil second line, for trajectory calculation\n");
		fclose(gg);
		exit(-1);
	}
}

void readThirdLine(char *buffer, FILE *gg){
	if(fgets(buffer,bufferSize,gg) == nullptr){
		std::cout<< "error" << "\n";
	}

	float one;
	float three;
	char smt[50];
	if(sscanf(buffer,"%f %f %s\n",&one, &three, smt)!=2){
		printf("Wrong format of infil third line, for trajectory calculation\n");
		fclose(gg);
		exit(-1);
	}
}

void readFourthLine(char *buffer, FILE *gg){
	if(fgets(buffer,bufferSize,gg) == nullptr){
		std::cout<< "error" << "\n";
	}

	int a,b,c,d,e;
	char s1[50], s2[50], smt[50];
	if(sscanf(buffer,"%d %d %d %d %d %s %s %s\n",&a, &b, &c, &d, &e, s1, s2, smt)!=7){
		printf("Wrong format of infil fourth line, for trajectory calculation\n");
		fclose(gg);
		exit(-1);
	}
}

void readFifthLine(char *buffer, FILE *gg){
	if(fgets(buffer,bufferSize,gg) == nullptr){
		std::cout<< "error" << "\n";
	}

	int a,b,c;
	float d;
	char smt[50];
	if(sscanf(buffer,"%d %d %d %f %s\n",&a, &b, &c, &d, smt)!=4){
		printf("Wrong format of infil fifth line, for trajectory calculation\n");
		fclose(gg);
		exit(-1);
	}
}

void readSixthLine(char *buffer, FILE *gg){
	if(fgets(buffer,bufferSize,gg) == nullptr){
		std::cout<< "error" << "\n";
	}

	int a;
	float b,c,d;
	char smt[50];
	if(sscanf(buffer,"%d %f %f %f %s\n",&a, &b, &c, &d, smt)!=4){
		printf("Wrong format of infil sixth line, for trajectory calculation\n");
		fclose(gg);
		exit(-1);
	}
}

void readSeventhLine(char *buffer, FILE *gg){
	if(fgets(buffer,bufferSize,gg) == nullptr){
		std::cout<< "error" << "\n";
	}

	float a,b,c,d,e,f;
	char smt[50];
	if(sscanf(buffer,"%f %f %f %f %f %f %s\n",&a, &b, &c, &d, &e, &f, smt)!=6){
		printf("Wrong format of infil seventh line, for trajectory calculation\n");
		fclose(gg);
		exit(-1);
	}
}

void readEighthLine(char *buffer, FILE *gg){
	if(fgets(buffer,bufferSize,gg) == nullptr){
		std::cout<< "error" << "\n";
	}

	float a;
	char smt[50];
	if(sscanf(buffer,"%f %s\n",&a, smt)!=1){
		printf("Wrong format of infil eighth line, for trajectory calculation\n");
		fclose(gg);
		exit(-1);
	}
}
