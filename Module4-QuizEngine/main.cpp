#include "Quiz.h"

int main() {
    Quiz quiz("QZ-03");

    Question q1("Which feature hides data inside a class?",
                "Inheritance", "Encapsulation", "Compilation", "Recursion",
                'B', 5);

    Question q2("Which keyword makes data members inaccessible from outside?",
                "public", "static", "private", "friend",
                'C', 5);

    Question q3("What is used to read a private data member safely?",
                "Getter function", "Global variable", "goto", "Macro",
                'A', 10);

    quiz.addQuestion(q1);
    quiz.addQuestion(q2);
    quiz.addQuestion(q3);

    quiz.takeQuiz();
    quiz.showResult();

    return 0;
}
