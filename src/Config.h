// Config.h
#include <fstream>
#include <string>
#include <iostream>
using std::string;
using std::ifstream;
using std::map;
using std::getline;
using std::cout;

class Config
{
private:
    string filename;
    // Actual config parameters
    uint windowWidth;
    uint windowHeight;
    float circleSize;
    uint circleNum;

    Config(){}
    Config(const Config&) = delete;
    Config& operator = (const Config&) = delete;

public:
    static Config& getInstance()
    {
        static Config instance;
        return instance;
    }

    static Config& getInstance(int argc, char* argv[])
    {
        Config& instance = getInstance();
        instance.parseCommandLineArgs(argc, argv);
        instance.readFile();
        return instance;
    }

    uint getWindowWidth()
    {
        return windowWidth;
    }

    uint getWindowHeight()
    {
        return windowHeight;
    }

    float getCircleSize()
    {
        return circleSize;
    }

    uint getCircleNum()
    {
        return circleNum;
    }

private:
    // Parse command line arguments to get config file
    void parseCommandLineArgs(int argc, char* argv[])
    {
        for (int i=0; i<argc; i++)
        {
            if (string(argv[i]) == "-config")
            {
                filename = argv[i+1];
            }
        }
    }

    // Read config file
    void readFile()
    {
        ifstream file(filename);
        string line;
        while (getline(file, line))
        {
            size_t posi = line.find("=");
            if (posi != -1)
            {
                string key = line.substr(0, posi);
                string value = line.substr(posi+1);
                if (key == "windowWidth") {
                    windowWidth = atoi(value.c_str());
                } else if (key == "windowHeight") {
                    windowHeight = atoi(value.c_str());
                } else if (key == "circleSize") {
                    circleSize = atoi(value.c_str());
                } else if (key == "circleNum") {
                    circleNum = atoi(value.c_str());
                }
            }
        }
        cout << "windowWidth: " << windowWidth << std::endl;
        cout << "windowHeight: " << windowHeight << std::endl;
        cout << "circleNum: " << circleNum << std::endl;
        cout << "circleSize: " << circleSize << std::endl;
    }
};

// end of config.h