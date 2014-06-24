#include "huffman.h"
#include <map>

#include <iostream>
#include <ostream>

#include <algorithm>
#include <iterator>

#include <string>


std::ostream& operator<<(std::ostream& os, std::vector<bool> vec)
{
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<bool>(os, ""));
  return os;
}


int main()
{
  std::map<char, double> frequencies;
  frequencies['e'] = 0.124167;
  frequencies['a'] = 0.0820011;
  frequencies['t'] = 0.0969225;
  frequencies['i'] = 0.0768052;
  frequencies['n'] = 0.0764055;
  frequencies['o'] = 0.0714095;
  frequencies['s'] = 0.0706768;
  frequencies['r'] = 0.0668132;
  frequencies['l'] = 0.0448308;
  frequencies['d'] = 0.0363709;
  frequencies['h'] = 0.0350386;
  frequencies['c'] = 0.0344391;
  frequencies['u'] = 0.028777;
  frequencies['m'] = 0.0281775;
  frequencies['f'] = 0.0235145;
  frequencies['p'] = 0.0203171;
  frequencies['y'] = 0.0189182;
  frequencies['g'] = 0.0181188;
  frequencies['w'] = 0.0135225;
  frequencies['v'] = 0.0124567;
  frequencies['b'] = 0.0106581;
  frequencies['k'] = 0.00393019;
  frequencies['x'] = 0.00219824;
  frequencies['j'] = 0.0019984;
  frequencies['q'] = 0.0009325;
  frequencies['z'] = 0.000599;

  Hufftree<char, double> hufftree(frequencies.begin(), frequencies.end());

  for (char ch = 'a'; ch <= 'z'; ++ch)
  {
    std::cout << ch << ": " << hufftree.encode(ch) << "\n";
  }

  std::string source = "payamohajeri";

  std::cout << source << "\n\n";

  std::vector<bool> encoded = hufftree.encode(source.begin(), source.end());
  std::cout << encoded << "\n\n";

  std::string destination;
  hufftree.decode(encoded, std::back_inserter(destination));
  std::cout << destination << "\n\n";

  std::cout << "Enter String To encode :";
  std::cin >> source;
  
  encoded = hufftree.encode(source.begin(), source.end());
  std::cout << encoded << "\n\n";
  
  std::cout << "Enter Code To Decode :";
  std::cin >> destination;
  
  hufftree.decode(encoded, std::back_inserter(destination));
  std::cout << destination << "\n\n";

}

