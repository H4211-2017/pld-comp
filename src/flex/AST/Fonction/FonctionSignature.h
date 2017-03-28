#ifndef FONCTIONSIGNATURE_H
#define FONCTIONSIGNATURE_H

#include <string>

#include "AbstractNode.h"


namespace AST {

    class FonctionSignature : public AbstractNode
    {
    public:
    
    	FonctionSignature(std::string identifiant);
        FonctionSignature(std::string identifiant, Type type);

        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR() const;

        std::string getIdentifiant() const;
        Value getValue() const;
        

    private:
        std::string identifiant;
    };
}

#endif // FONCTIONSIGNATURE_H
