#include "kyheader.h"
#include "Objectness.h"
#include "ValStructVec.h"

int main(int argc, char* argv[])
{
    srand((unsigned int)time(NULL));

    if (argc < 2)
    {
        fprintf(stderr, "usage: annotation/dir/with/yaml\n");
        return -1;
    }

    DataSetVOC voc2007(argv[1]);
    voc2007.cvt2OpenCVYml(argv[1]);
    cout << endl;
    return 0;
}
