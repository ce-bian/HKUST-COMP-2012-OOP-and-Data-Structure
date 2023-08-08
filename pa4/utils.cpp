 #include "utils.h"

Utils::Utils()  {}

Utils::~Utils()
{
    tree.release();
}

bool Utils::loadDictionary(const string& text_dic)
{
    // load the file with name text_dic, and save all characters in this->content
    ifstream load_file(text_dic);
    if (!load_file.is_open()) {
        cout << "Failed to load the article. Exit." << endl;
        return false;
    }

    ostringstream buf;
    char ch;
    while (buf && load_file.get(ch))
        buf.put(ch);
    this->content = buf.str();
    // move out the end useless '\r' of a file
    this->content.pop_back();

    load_file.close();

    // scan the string this->content, calculate the frequency table
    // insert your code here ...
   for(int i=0;i<content.length();i++){
    	char temp=content.at(i);
    	map<char,int>::const_iterator p;
    	int num=0;
    	for(p=frequency_table.begin();p!=frequency_table.end();++p){
    		if(p->first==temp){
    		  int num=p->second+1;
    		  frequency_table.erase(temp);
    		  frequency_table.insert(pair<char,int>(temp,num));
    		  break;
    		}
    		num++;
    	}
    	if(frequency_table.size()==0||num==frequency_table.size())
    	    frequency_table.insert(pair<char,int>(temp,1));

    }

    return true;
}

void Utils::buildTree()
{
    tree.loadMap(frequency_table);
}

void Utils::setEncodedTable()
{
    tree.encode(encoded_table);
}

void Utils::saveBinDictionary(const string& bin_file)
{
    // load key file
    ifstream ifile("xor_key.bin", ios::binary);
    if (!ifile.is_open()) {
        cout << "cannot load key file, exit." << endl;
        return;
    }

    ofstream ofile(bin_file, ios::binary);

    // assuming that the length of bin_code is multiple of 8
    // so just for every 8 continuous {0,1} characters, intepret it as a binary byte number
    // for last byte you write, its valid length may be less than 8, fill the invalid bits with 0
    // eg., last byte contains only 3 valid bits, 110. You should fill it as 1100 0000, and then
    // you need to write integer 3 (bin form: 0000 0011) as one byte at the beginning of your binary file.
    // after saving data into .bin file, you should print out its hex form in command line
    // insert your code here ...
    string txt="";
    for(int i=0;i<content.length();i++)
         txt=txt+encoded_table[content.at(i)];
    int cut=txt.length()%8;

    for(int i=0;i<8-cut;i++){
    		txt=txt+"0";
    }
   // unsigned char remainder=cut;

   // stack<char> bin;
    int number=0;
    while(cut!=0){
    	if(cut%2==0)
    	   txt="0"+txt;
    	else if(cut%2==1)
         // bin.push('1');
    		txt="1"+txt;
    	cut/=2;
    	number++;
    }

   /* char* first=new char[bin.size()];
    for(int i=0;i<bin.size();i++){
    	first[i]=bin.top();
    	bin.pop();
    }
    */
    //string magic(first);
    for(int i=0;i<8-number;i++){
    	txt="0"+txt;
    }
    //txt=magic+txt;
    //cout<<txt;

    string code="";
    string temp;
    char input;

   for(int i=0;i<txt.length()/8;i++){
    	ifile.get(input);
    	int num=i*8;
    	temp=txt.substr(num,8);
    	unsigned char temp1=stoi(temp,NULL,2);
    	code+=temp1^(unsigned char)input;

    	cout<<hex<<(int)(temp1^(unsigned char)input);
    }
   ifile.close();
   ofile<<code;
   ofile.close();
   cout<<endl;
   cout<<endl;



    

}

void Utils::decode(const string& bin_file)
{
    ifstream ifile(bin_file, ios::binary);
    if (!ifile.is_open()) {
        cout << "cannot open .bin file, stop decoding." << endl;
        return;
    }

    ifstream key_file("xor_key.bin", ios::binary);
    if (!key_file.is_open()) {
        cout << "cannot load key file, exit." << endl;
        return;
    }
    
    // the string used to search on huffman tree to decode as plaintext
    string bit_str = "";

    // bin_file: stores a binary huffman code with possible extra bits at the end
    // key_file: decryption XOR key
    // search in the encoded table
    // insert your code here ...
    //char binary;
    char key;
    string result;
    getline(ifile,result);
    char temp;
    int cutoff;
    int code;
    for(int i=0;i<result.length();i++){
    	string binary="";
    	key_file.get(key);
    	temp=result.at(i);
    	if(i==0){
    		//unsigned char temp1=stoi(temp,NULL,2);
    		cutoff=(int)((unsigned char)temp^(unsigned char)key);
    		break;
    	}


        //unsigned char temp2=stoi(temp,NULL,2);
    	code=(int)((unsigned char)temp^(unsigned char)key);
    	for(int i=0;i<8;i++){
    		if(code%2==1)
    			binary="1"+binary;
    		else
    			binary="0"+binary;
    		code/=2;
    	}
    	cout<<binary<<" ";
    	bit_str+=binary;
    }
       //string last =result.substr(result.length()-8,8);
       // remaining=last.substr(0,cutoff);
      // bit_str+=remaining;



    ifile.close();
    key_file.close();

    // using huffman tree you've built before to decode the bit string
    string plaintext = tree.decode(bit_str);
    cout << plaintext << endl << endl;
}
