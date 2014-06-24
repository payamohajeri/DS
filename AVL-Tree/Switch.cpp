    Tree Tree;
    int ch;
    int temp;
    while(1)
    {
		cout<<endl;
		cout<<" AVL Tree Operations "<<endl;
		cout<<" ------------------------------"<<endl;
		cout<<" 1. Insertion "<<endl;
		cout<<" 2. Deletion "<<endl;
		cout<<" 3. Exit "<<endl;
		cout<<" Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<" Enter Number to be inserted : ";
				cin>>temp;
				Tree.Insert(temp);//SASASASASA
				break;
			case 2: cout<<" Enter Number to be deleted : ";
				cin>>temp;
				Tree.Remove(temp);//SASASASASASASAS
				break;
			case 3: system("pause");
				return 0;
    			break;
		};
	}
