#ifndef FC_BISON_H
#define FC_BISON_H

#include <map>
#include <memory>
#include "Variable.h"

struct InfosSigVar {
	int type = -1; //0 char - 1 int32 - 2 int64
        std::string id = "";
};
typedef struct InfosSigVar InfosSigVar;



//void createVariable(std::shared_ptr< mapVar > variables, InfosSigVar infos);

//void affectVariable(std::shared_ptr< mapVar > variables, std::string id, char valeur);
//void affectVariable(std::shared_ptr< mapVar > variables, std::string id, int valeur);
//void affectVariable(std::shared_ptr< mapVar > variables, std::string id, long int valeur);

#endif //FC_BISON_H
