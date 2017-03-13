#include "Label.h"

Label::Label()
{

}

std::string Label::getLabelName(){
    return labelName;
}

void Label::setLabelName(std::string name){
    labelName =name;
}
