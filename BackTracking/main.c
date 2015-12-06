void permuteTest();
void knightTourTest();
void ratInMazeTest();
void solveNQueen();
void solveSubSetSum(int k);
void coloringProblem(int c);
void hamiltonianCycleMain();

void unitTests()
{
    permuteTest();
    knightTourTest();
    ratInMazeTest();
    solveNQueen();
    solveSubSetSum(35);
    coloringProblem(3);
    hamiltonianCycleMain();
}
int main()
{
    //unitTests();

    hamiltonianCycleMain();
    return 0;
}
