#include <string>
#include <iostream>
#include <fstream>

std::string   filereplace(std::string &content, std::string &replaced, std::string &toreplace)
{
    size_t i = 0;

    do {
            i = content.find(replaced, i);
            if (i != std::string::npos)
            {
                content = content.substr(0, i) + toreplace + content.substr(i + replaced.length(), content.size());
                i += toreplace.size();
            }
        } while (i!= std::string::npos);
    return (content);
}


int main(int ac, char **av)
{
    std::ifstream    fd;
    std::ofstream    fd2;
    std::string     content;
    
    if (ac != 4)
    {
        std::cout << "3 parameters are needed" << std::endl;
        return (0);
    } 
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string buf;

    if (s1 == "" || s2 == "")
    {
        std::cout << "fields can't be empty" << std::endl;
        return (0);
    }
    fd.open(filename.c_str(), std::ios::in);
	if (fd.fail())
	{
		std::cout << "Invalid file." << std::endl;
		return (0);
	}
	fd2.open((filename + ".replace").c_str());
    
    while (std::getline(fd, buf))
    {
        buf = filereplace(buf, s1, s2);
        fd2 << buf << std::endl;
    }
    fd.close();
    fd2.close();
}