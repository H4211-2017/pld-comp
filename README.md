# Compilation:
Se déplacer dans le dossier racine du projet (celui contenant CMakeList.txt)  
Exécuter:  
    `cmake .`  
    `make`  
    
L'exécutable <lake> se trouve dans le dossier 'bin'  

# Exécution:  
La ligne de commande à exécuter est:  
lake [srcFile] [-v] [-S <AsmTarget>] [ -o <ExecTarget>] [ -t <AstTarget>] [-On] 

    * srcfile:  
        Le fichier source que le compilateur compilera. Si aucun fichier source n'est fourni, l'entrée standard est utilisée.  
    * -v:  
        Le compilateur affichera en console l'analyse flex effectué, puis l'arbre AST produit, puis l'IR.  
    * -S:  
        AsmTarget est le nom du fichier assembleur généré. Par défaut, si l'option n'est pas spécifié, ou si AsmTarget est la chaîne nul, le fichier généré est 'a.s'.  
    * -o:  
        ExecTarget est le nom du fichier exécutable généré (gcc est utilisé à partir de l'assembleur généré par notre compilateur). Si l'option '-S' n'est pas spécifié, le fichier assembleur est supprimé. Si '-o' n'est pas spécifié, aucun exécutable n'est généré.  
    * -t:  
        AstTarget est le nom du fichier qui contiendra l'arbre AST généré par le programme. Si l'option '-v' est spécifié, l'arbre AST est affiché dans la sortie standard, et dans le fichier AstTarget. Par défaut, aucun fichier n'est généré.  
    * -On:  
        n peut valoir 0, 1 ou 2, et représente les différents niveaux d'optimisation. Par défaut, le niveau 0 est utilisé. -O1 supprime les écritures mémoires qui ne seront jamais lu, et -O2 supprime les lectures depuis les mémoires quand la valeur est déjà dans un registre (en plus de réaliser les optimisations de -O1).  
    
# Features:
On gère:  

    * La déclaration anticipé de fonction.  
    * L'appel de fonction, avec et sans paramètres, maximum 6 paramètres (y compris appel récursif).  
    * Le retour de fonction, void ou non.  
    * Les structures de contrôle IF, WHILE et FOR.  
    * Les opérations:  
        * Binaire (+, -, ...)  
        * Unaires (- unaire, + unaire, !, ~, -- et ++ avant et aprés la variable)  
    * Les affectations, y compris avec opérations (+=, *=, ...).  
    * La portée des variables.  
    * La redéclaration de variable dans une portée plus petite ("int a; {int a;}")  
    

    
# Bugs connus:

* Le compilateur ne donne pas l'erreur précise dans un fichier non compilable, mais sort en SegFault.  
* La structure If/Else If ne compile pas, mais la structure If/Else If/Else compile.  
* L'instruction break et continue ne fonctionne pas (mais compile).  
* L'instruction return ne compile pas si elle est placé dans un if, mais fonctionne dans un while.  
* La structure de contrôle IF ne compile pas si il n'y a pas d'instruction après (une structure de contrôle est une instruction).  

# Features non gérés:

* Les tableaux ne sont pas pris en compte par l'IR.  
* Le main peut déclarer des arguments, mais ne peut pas les utiliser.  
* Les fonctions définies dans d'autres fonctions.  
* Les variables globales.  
 




