#include "kyheader.h"
#include "Objectness.h"
#include "ValStructVec.h"
#include "CmShow.h"

int main(int argc, char* argv[])
{
    int W = 2, NSS = 8, numPerSz = 130;
    double base = 2.0;
    if (argc < 2)
    {
        fprintf(stderr, "usage: work/directory/\n");
        return -1;
    }

    srand((unsigned int)time(NULL));
    DataSetVOC voc2007(argv[1]);
    voc2007.loadAnnotations();

    Objectness objNess(voc2007, base, W, NSS);

    objNess.evaluateIJCV13();
}
