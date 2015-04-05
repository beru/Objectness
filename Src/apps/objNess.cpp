#include "kyheader.h"
#include "Objectness.h"
#include "ValStructVec.h"
#include "CmShow.h"

int main(int argc, char* argv[])
{
    int W = 8, NSS = 2, numPerSz = 130;
    double base = 2.0;
    srand((unsigned int)time(NULL));

    if (argc < 2)
    {
        fprintf(stderr, "usage: voc-dir\n");
        return -1;
    }

    DataSetVOC voc2007(argv[1]);
    voc2007.loadAnnotations();

    Objectness objNess(voc2007, base, W, NSS);

    vector<vector<Vec4i>> boxesTests;
    objNess.getObjBndBoxesForTests(boxesTests, 250);
}
