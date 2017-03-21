#ifndef FC_BISON_H
#define FC_BISON_H

#include <map>
#include <memory>
#include "Variable.h"

using namespace std;

struct InfosSigVar {
	int type = -1; //0 char - 1 int32 - 2 int64
	string id = "";
};
typedef struct InfosSigVar InfosSigVar;

typedef map< string, shared_ptr< Variable > > mapVar;

void createVariable(shared_ptr< mapVar > variables, InfosSigVar infos);

void affectVariable(shared_ptr< mapVar > variables, string id, char valeur);
void affectVariable(shared_ptr< mapVar > variables, string id, int valeur);
void affectVariable(shared_ptr< mapVar > variables, string id, long int valeur);

#endif //FC_BISON_H
