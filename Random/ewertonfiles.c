/*
FILE *fp;      // Declare a pointer to a FILE object

fp = fopen("text.txt", "w+");   // Open or create "text.txt" for reading and writing

rewind(fp);    // Set the file position indicator to the beginning of the file

ftell(fp);     // Get the current file position indicator's position

feof(fp);      // Check if the end-of-file indicator for the stream fp is set

fputs("hello", fp);   // Write the string "hello" to the file pointed to by fp

fclose(fp);    // Close the file associated with fp
*/