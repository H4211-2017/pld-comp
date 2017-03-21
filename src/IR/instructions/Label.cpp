#include "Label.h"

using namespace IR;

Label::Label()
{

}

std::string Label::getLabelName(){
    return labelName;
}

void Label::setLabelName(std::string name){
    labelName =name;
}
