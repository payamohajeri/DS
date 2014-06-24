#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename Elem>

void CreateOutput(Elem * Base, int BaseSize, Elem * PreOrder, Elem * PostOrder, Elem * InOrder, int TravesalSize)
{

	ofstream Output;
	Output.open("./Output/Output.html", ios::out | ios:: trunc);

	Output << "<html>\n";
	Output << "<head>\n";
	Output << "<title>Graphical Output</title>\n";
	Output << "<script type='text/javascript' src='ECOTree.js'></script>\n";
	Output << "<link type='text/css' rel='stylesheet' href='ECOTree.css' />\n";
	Output << "<xml:namespace ns='urn:schemas-microsoft-com:vml' prefix='v'/>\n";
	Output << "<style>v\\:*{ behavior:url(#default#VML);}</style>\n";
	Output << "<script>\n";
	Output << "var myTree = null;\n";
	Output << "function CreateTree() {\n";
	Output << "myTree = new ECOTree('myTree','myTreeContainer');\n";
	Output << "myTree.config.linkType = 'B';\n";
	Output << "myTree.config.topYAdjustment = 0;\n";
	Output << "myTree.config.topXAdjustment = 0;\n";
	Output << "myTree.config.linkColor = 'black';\n";
	Output << "myTree.config.nodeColor = '#FFAAAA';\n";
	Output << "myTree.config.nodeBorderColor = 'black';\n";
	Output << "myTree.config.useTarget = false;\n";
	Output << "myTree.config.selectMode = ECOTree.SL_SINGLE;\n";


	if (Base[0] == -1000 || BaseSize == 0 )
	{
		Output << "myTree.add(0,-1," << "EMPTY TREE" << ");\n" ;
		return (1);
	}
	
	else
	{
		Output << "myTree.add(0,-1," << Base[0] << ",40,40);\n" ;
		int counter = 1;
		int j;
		
		for (int i=1 ; i<BaseSize; i++)
		{
			j= (i-1)/2;
			
			if (Base[i] == -1000)
			{
				continue;
			}
			else
			{
				Output << "myTree.add(" << counter << "," << j << "," << Base[i] << ",40,40);\n" ;
				counter ++ ;		
			}	
		}
	}


	Output << "myTree.UpdateTree();\n";
	Output << "}\n</script>\n";
	Output << "</head>\n<body onload='CreateTree();'>\n";
	Output << "<hr />\n";
	Output << "<div style='float : center;' align='center'>\n";
	Output << "<pre align='center'>";
	Output << "PreOrde :\t";
	
	for (int i=0 ; i < TravesalSize ; i++)
	{
		Output << PreOrder[i] << "  " ;
	}
	
	Output << "\n";
	Output << "</pre>";
	Output << "<hr />\n";
	Output << "<pre align='center'>";
	Output << "PostOrder :\t";
	
	for (int i=0 ; i < TravesalSize ; i++)
	{
		Output << PostOrder[i] << "  " ;
	}
	
	Output << "\n";
	Output << "</pre>";
	Output << "<hr />\n";
	Output << "<pre align='center'>";
	Output << "inOrder :\t";
	
	for (int i=0 ; i < TravesalSize ; i++)
	{
		Output << InOrder[i] << "  " ;
	}
	
	Output << "\n";
	Output << "</pre>";
	Output << "<hr />\n";
	Output << "</div>";
	Output << "<div id='myTreeContainer' style='float : center; align : center;'>\n";
	Output << "</div>\n";
	Output << "<hr />\n";
	Output << "</body>\n";
	Output << "</html>\n";
	
	Output.close();
	return (0);

}
