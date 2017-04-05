#ifndef VALUE_H
#define VALUE_H

#include <utility>
#include "../../../IR/data/AbstractData.h"

namespace AST {
    enum Type
    {
        CHAR,
        INT_32,
        INT_64,
        ERROR
    };
    typedef enum Type Type;

    class Value
    {

    public:
		/**
		 * @brief Value Constructor by default
		 */
        Value();
        
        /**
         * @brief Value Constructor
         * @param type AST::Type, the type attribute's value
         * @param value long int, the value attribute's value
         */
        Value(Type type, long int value);
		
		/**
		 * @brief setter for the value attribute
		 * @param value a long int that will be the new value of this instance's value attribute
		 */
        void setValue(long int value);
        
        /**
         * @brief getter for the instance's attribute
         * @return a pair like <TYPE, VAL> where TYPE is this instance's type attribute and VAL this instance's value attribute
         * @remark TYPE is of type AST::Type and VAL is of type long int
         */
        std::pair<Type, long int> getValue() const;
        
        /**
		* @brief buildIR build the IR, and put the correspondant instructions in the provided basic block
		* @param currentBasicBlock IR::sh_BasicBlock & currentBasicBlock, the reference to a shared pointer on the current BasicBlock 
		* 		that is currently being completed
		* @return a shared pointer on the IR memory index that will contain the node's value once evaluated or nullptr if the node
		* 		shouldn't be callable
		*/
        IR::Type getIRType() const;

    private:
        Type type;
        long int value;
    };
}


#endif // VALUE_H
