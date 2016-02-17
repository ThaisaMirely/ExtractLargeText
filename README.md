# Extract Text -- extracts specific size of text in a larger file. --
Tool for extracting text specific sizes of an input file and generate an output file

-- In terminal, execute:

   g++ main -o elt

-- Execute the command:  
         $elt inputfile outputfile size
         
*size in Kb;
  
Example:  ./elt input_file_50MB.txt output_text.txt 1000
        ou 
        ./elt input_file_50MB.txt output_text.txt -b 1000
  
Result: extract from the input file that has 50mb of size, 1mb of text and stores it in a text file.


