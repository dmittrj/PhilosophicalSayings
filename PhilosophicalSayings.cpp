#include <iostream>
using namespace std;

string Saying;
string subjects[] = { "человек", "бог", "философия"};
int subjectsCount = 3;
string actions[] = { "существует", "мыслит", "думает", "есть"};
int actionsCount = 3;
string thinkAbout[] = { "о вечном", "о свободе", "о себе", "о смысле бытия", "о смерти", "о жизни"};
int thinkAboutCount = 6;

int rnd1(int x) {
    return rand() % x;
}

int rnd(int x, int y) {
    return (rnd1(y - x) + x);
}

void ActionStop() {
    int Not = rnd1(3);
    if (!Not) Saying += " не";
    int phr = rnd(0, actionsCount);
    Saying += " " + actions[phr];
    if ((phr == 1) || (phr == 2)) {
        if (!rnd1(6)) Saying += " " + thinkAbout[rnd(0, thinkAboutCount)];
    }
}

void ObjectStop() {
    Saying += " " + subjects[rnd(0, subjectsCount)];
}

void When() {
    if (!rnd1(5)) Saying += ", когда"; 
    else Saying += " только когда";
    int SecondSubject = rnd(1, 3);
    switch (SecondSubject)
    {
    case 1:
        ActionStop();
        break;
    case 2:
        ObjectStop();
        ActionStop();
        break;
    default:
        break;
    }
}

void And() {
    if (!rnd1(3)) { 
        Saying += ", а";
        ObjectStop();
        ActionStop();
    }
    else { 
        Saying += " и";
        ActionStop();
    }
}


void If() {
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
        ActionStop();
        break;
    case 2:
        ObjectStop();
        ActionStop();
        break;
    default:
        break;
    }
}

void Action() {
    /*int Not = rnd1(3);
    if (!Not) Saying += " не";
    int phr = rnd(0, actionsCount);
    Saying += " " + actions[phr];
    if ((phr == 1) || (phr == 2)) {
        if (!rnd1(6)) Saying += " " + thinkAbout[rnd(0, thinkAboutCount)];
    }*/
    ActionStop();
    int AfterAction = rnd(1, 4);
    switch (AfterAction)
    {
    case 1:
        When();
        break;
    case 2:
        If();
        break;
    case 3:
        And();
        break;
    default:
        break;
    }
}


void Subject() {
    Saying += " " + subjects[rnd(0, subjectsCount)];
    int ActionType = rnd(1, 2);
    switch (ActionType)
    {
    case 1:
        Action();
        break;
    default:
        break;
    }
}

void Start() {
    int QuestionType = rnd(1, 2);
    switch (QuestionType)
    {
    case 1:
        Subject();
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
