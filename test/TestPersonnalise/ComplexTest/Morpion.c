#include <stdio.h>
#include <stdlib.h>
void victoire(char c);

int32_t main()
{
    char case1 = '-';
    char case2 = '-';
    char case3 = '-';
    char case4 = '-';
    char case5 = '-';
    char case6 = '-';
    char case7 = '-';
    char case8 = '-';
    char case9 = '-';
    int32_t choix;
    int32_t choix2;

    while(1)
    {
        putchar(10);
        putchar('J');
        putchar('o');
        putchar('u');
        putchar('e');
        putchar('u');
        putchar('r');
        putchar(' ');
        putchar('1');
        putchar(' ');
        putchar('?');
        putchar(' ');
        putchar('(');
        putchar('X');
        putchar(')');
        putchar(10);

        //Joueur 1
        choix = getchar();
        choix2 = getchar();
        choix = choix - '0';
        if (choix == 1){case1='X';}
        if (choix == 2){case2='X';}
        if (choix == 3){case3='X';}
        if (choix == 4){case4='X';}
        if (choix == 5){case5='X';}
        if (choix == 6){case6='X';}
        if (choix == 7){case7='X';}
        if (choix == 8){case8='X';}
        if (choix == 9){case9='X';}

        //Affichage du plateau
        putchar(10);
        putchar(10);
        putchar(case1);
        putchar(' ');
        putchar(case2);
        putchar(' ');
        putchar(case3);
        putchar(10);
        putchar(case4);
        putchar(' ');
        putchar(case5);
        putchar(' ');
        putchar(case6);
        putchar(10);
        putchar(case7);
        putchar(' ');
        putchar(case8);
        putchar(' ');
        putchar(case9);
        putchar(10);
        
        //8 conditions de victoire
        while ((case1==case2)&&(case2==case3)&&case1!='-'){victoire(case1); return 0;}
        while ((case4==case5)&&(case5==case6)&&case4!='-'){victoire(case4); return 0;}
        while ((case7==case8)&&(case8==case9)&&case7!='-'){victoire(case7); return 0;}
        while ((case1==case4)&&(case4==case7)&&case1!='-'){victoire(case4); return 0;}
        while ((case2==case5)&&(case5==case8)&&case2!='-'){victoire(case5); return 0;}
        while ((case3==case6)&&(case6==case9)&&case3!='-'){victoire(case6); return 0;}
        while ((case1==case5)&&(case5==case9)&&case1!='-'){victoire(case1); return 0;}
        while ((case3==case5)&&(case5==case7)&&case3!='-'){victoire(case5); return 0;}

        // Joueur 2
        putchar(10);
        putchar('J');
        putchar('o');
        putchar('u');
        putchar('e');
        putchar('u');
        putchar('r');
        putchar(' ');
        putchar('2');
        putchar(' ');
        putchar('?');
        putchar(' ');
        putchar('(');
        putchar('O');
        putchar(')');
        putchar(10);

        choix2 = getchar();
        choix = getchar();
        choix2 = choix2 - '0';

        if (choix2 == 1){case1='O';}
        if (choix2 == 2){case2='O';}
        if (choix2 == 3){case3='O';}
        if (choix2 == 4){case4='O';}
        if (choix2 == 5){case5='O';}
        if (choix2 == 6){case6='O';}
        if (choix2 == 7){case7='O';}
        if (choix2 == 8){case8='O';}
        if (choix2 == 9){case9='O';}


        putchar(10);
        putchar(10);
        putchar(case1);
        putchar(' ');
        putchar(case2);
        putchar(' ');
        putchar(case3);
        putchar(10);
        putchar(case4);
        putchar(' ');
        putchar(case5);
        putchar(' ');
        putchar(case6);
        putchar(10);
        putchar(case7);
        putchar(' ');
        putchar(case8);
        putchar(' ');
        putchar(case9);
        putchar(10);

        //8 conditions de victoire
        while ((case1==case2)&&(case2==case3)&&case1!='-'){victoire(case1); return 0;}
        while ((case4==case5)&&(case5==case6)&&case4!='-'){victoire(case4); return 0;}
        while ((case7==case8)&&(case8==case9)&&case7!='-'){victoire(case7); return 0;}
        while ((case1==case4)&&(case4==case7)&&case1!='-'){victoire(case4); return 0;}
        while ((case2==case5)&&(case5==case8)&&case2!='-'){victoire(case5); return 0;}
        while ((case3==case6)&&(case6==case9)&&case3!='-'){victoire(case6); return 0;}
        while ((case1==case5)&&(case5==case9)&&case1!='-'){victoire(case1); return 0;}
        while ((case3==case5)&&(case5==case7)&&case3!='-'){victoire(case5); return 0;}

    }
}

void victoire(char c){
    putchar('V');
    putchar('i');
    putchar('c');
    putchar('t');
    putchar('o');
    putchar('i');
    putchar('r');
    putchar('e');
    putchar(' ');
    putchar(c);
    putchar(' ');
    putchar('!');
    putchar(10);
}
