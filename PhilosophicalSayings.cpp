#include <iostream>
using namespace std;

string Saying;
string LastWord;
string subjects[] = { "человек", "бог", "всевышний", "философ"};
int subjectsCount = 4;
string abstractsubjects[] = { "бытие", "космос", "религия", "философия", "материя", "сознание", "вселенная", "добро", "карма", "хаос"};
int abstractsubjectsCount = 10;
string actions[] = { "существует", "мыслит", "думает", "есть", "бесполезен"};
int actionsCount = 5;
string abstractactions[] = { "существует", "есть", "везде", "нигде"};
int abstractactionsCount = 4;
string thinkAbout[] = { "о вечном", "о свободе", "о себе", "о смысле бытия", "о смерти", "о жизни"};
int thinkAboutCount = 6;
string liveIn[] = { "в мире", "во вселенной", "в пространстве"};
int liveInCount = 3;

int rnd1(int x) {
    return rand() % x;
}

int rnd(int x, int y) {
    return (rnd1(y - x) + x);
}

void ActionStop(int ab) {
    int Not = rnd1(3);
    if (!Not) Saying += " не";
    if (!ab) {
        int phr = rnd(0, actionsCount);
        Saying += " " + actions[phr];
        if ((phr == 1) || (phr == 2)) {
            if (!rnd1(5)) Saying += " " + thinkAbout[rnd(0, thinkAboutCount)];
        }
        if (phr == 0) {
            if (!rnd1(7)) Saying += " " + liveIn[rnd(0, liveInCount)];
        }
    } else {
        int phr = rnd(0, abstractactionsCount);
        Saying += " " + abstractactions[phr];
    }
}

int ObjectStop() {
    int ab = rnd1(4);
    if (!ab) {
        int y = rnd(0, subjectsCount);
        Saying += " " + subjects[y];
        LastWord = subjects[y];
    }
    else {
        int z = rnd(0, abstractsubjectsCount);
        Saying += " " + abstractsubjects[z];
        LastWord = abstractsubjects[z];
    }
    return ab;
}

void When(int ab) {
    if (!rnd1(5)) Saying += ", когда"; 
    else Saying += " только когда";
    int SecondSubject = rnd(1, 3);
    switch (SecondSubject)
    {
    case 1:
        ActionStop(ab);
        break;
    case 2:
        ActionStop(ObjectStop());
        break;
    default:
        break;
    }
}

void And(int ab) {
    if (!rnd1(3)) { 
        if (!rnd1(5)) {
            Saying += ", но";
            ActionStop(ObjectStop());
        }
        else {
            Saying += ", а";
            ActionStop(ObjectStop());
        }
    }
    else { 
        Saying += " и";
        ActionStop(ab);
    }
}


void If(int ab) {
    int IfForm = rnd(1, 5);
    switch (IfForm)
    {
    case 1:
        Saying += ", если";
        break;
    case 2:
        Saying += " только если";
        break;
    case 3:
        Saying += " только в том случае, если";
        break;
    case 4:
        Saying += " в том случае, если";
        break;
    default:
        break;
    }
    int SecondSubject = rnd(1, 3);
    switch (SecondSubject)
    {
    case 1:
        ActionStop(ab);
        break;
    case 2:
        ActionStop(ObjectStop());
        break;
    default:
        break;
    }
}

void Because(int ab) {
    int IfForm = rnd(1, 5);
    switch (IfForm)
    {
    case 1:
        Saying += ", потому что";
        break;
    case 2:
        Saying += " из-за того, что";
        break;
    case 3:
        Saying += " только потому, что";
        break;
    case 4:
        Saying += ", ведь";
        break;
    default:
        break;
    }
    int SecondSubject = rnd(2, 3);
    switch (SecondSubject)
    {
    case 1:
        ActionStop(ab);
        break;
    case 2:
        ActionStop(ObjectStop());
        break;
    default:
        break;
    }
}



void Action(int ab) {
    /*int Not = rnd1(3);
    if (!Not) Saying += " не";
    int phr = rnd(0, actionsCount);
    Saying += " " + actions[phr];
    if ((phr == 1) || (phr == 2)) {
        if (!rnd1(6)) Saying += " " + thinkAbout[rnd(0, thinkAboutCount)];
    }*/
    ActionStop(ab);
    int AfterAction = rnd(1, 6);
    switch (AfterAction)
    {
    case 1:
        When(ab);
        break;
    case 2:
        If(ab);
        break;
    case 3:
        And(ab);
        break;
    case 4:
        Because(ab);
        break;
    default:
        break;
    }
}


void Subject() {
    int ab = rnd1(4);
    if (!ab) {
        Saying += " " + subjects[rnd(0, subjectsCount)];
    }
    else {
        Saying += " " + abstractsubjects[rnd(0, abstractsubjectsCount)];
    }
    int ActionType = rnd(1, 2);
    switch (ActionType)
    {
    case 1:
        Action(ab);
        break;
    default:
        break;
    }
}

void IfThen() {
    Saying += " если";
    ActionStop(ObjectStop());
    Saying += ", то";
    ActionStop(ObjectStop());
    if (rnd1(4)) return;
    int AndForm = rnd(1, 5);
    switch (AndForm)
    {
    case 1:
        Saying += " и";
        ActionStop(ObjectStop());
        break;
    case 2:
        Saying += ", а";
        ActionStop(ObjectStop());
        break;
    case 3:
        Saying += ", но если";
        ActionStop(ObjectStop());
        Saying += ", то";
        ActionStop(ObjectStop());
        break;
    case 4:
        Saying += ", ведь";
        ActionStop(ObjectStop());
        break;
    default:
        break;
    }
}

void ItIs() {
    ObjectStop();
    Saying += " — это";
    ObjectStop();
    if (rnd1(3)) return;
    int AndForm = rnd(1, 5);
    switch (AndForm)
    {
    case 1:
        Saying += " или";
        ObjectStop();
        break;
    case 2:
        Saying += " и";
        ObjectStop();
        break;
    case 3:
        Saying += ", котор";
        if ((LastWord[LastWord.length() - 1] == 'а') ||
            (LastWord[LastWord.length() - 1] == 'я'))
            Saying += "ая";
        else if ((LastWord[LastWord.length() - 1] == 'е') ||
                  LastWord[LastWord.length() - 1] == 'о')
            Saying += "ое";
        else Saying += "ый";
        if (rnd1(3)) Saying += " не";
        Saying += " есть";
        ObjectStop();
        break;
    case 4:
        Saying += ", ведь";
        ActionStop(ObjectStop());
        break;
    default:
        break;
    }
}


void Start() {
    int QuestionType = rnd(1, 4);
    switch (QuestionType)
    {
    case 1:
        Subject();
        break;
    case 2:
        IfThen();
        break;
    case 3:
        ItIs();
        break;
    default:
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    p:
    system("cls");
    Saying = "";
    Start();
    Saying[1] = Saying[1] - 32;
    cout << endl << Saying << endl << endl << endl;
    system("pause");
    goto p;
}
