

struct AI
{
    const static unsigned short LAYER_COUNT = 3;
    const static unsigned short LAYER_DEPTH = 4;
    const static unsigned short INPUT_COUNT = 4;
    bool training = false;

    unsigned char topology[3]{
	3, 4, 1
    };



    unsigned char weights[LAYER_COUNT][LAYER_DEPTH][LAYER_DEPTH]{
    	{{255, 0, 0, 0}, {255, 0, 0, 0}, {255, 0, 0, 0}, {0, 0, 0, 0}},
    	{{255, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    	{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}
    };
    char biases[LAYER_COUNT][LAYER_DEPTH]{
    	{0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    unsigned char tmp[4]{0, 0, 0, 0};
    unsigned char curr[4]{0, 0, 0, 0};
    unsigned char* run(unsigned char* input);
    void train(unsigned int data_points,unsigned char** traindata);
    void save(FILE* file);
    void load(FILE* file);
};
