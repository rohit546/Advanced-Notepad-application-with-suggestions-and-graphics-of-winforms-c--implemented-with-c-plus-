# Advanced-Notepad-application-with-suggestions-and-graphics-of-winforms-c-implemented-with-c--
This was my data lab project the project is about smart notepad with suggestion and encoding and decoding of text through huffman trees and suggestions are with trie data structure its a full working application

<img width="452" alt="Screenshot 2022-12-21 162559" src="https://user-images.githubusercontent.com/100420859/208898380-e3d7b9b1-aff9-4bbb-8db1-bf5f33e1e721.png">
<img width="448" alt="Screenshot 2022-12-21 162627" src="https://user-images.githubusercontent.com/100420859/208898402-0785f8bf-371f-418d-94e9-2e086ae81e8d.png">
<img width="449" alt="Screenshot 2022-12-21 162646" src="https://user-images.githubusercontent.com/100420859/208898426-87f63b90-bb4d-4a9c-a371-0fcf4a4cf54e.png">
<img width="449" alt="Screenshot 2022-12-21 162646" src="https://user-images.githubusercontent.com/100420859/208898450-149d0a5c-c889-481d-8364-3744d549b2b5.png">
<img width="434" alt="Screenshot 2022-12-21 162733" src="https://user-images.githubusercontent.com/100420859/208898475-60fb8821-06aa-4264-ba8a-27e6dfb00bfa.png">
<img width="456" alt="Screenshot 2022-12-21 162751" src="https://user-images.githubusercontent.com/100420859/208898487-2974801f-574e-4631-ab73-f416d2d0cbfe.png">
<img width="441" alt="Screenshot 2022-12-21 162817" src="https://user-images.githubusercontent.com/100420859/208898506-19da66bd-d481-4d30-a0fe-8373c76aee04.png">

Data Structures
Project Description
CL-2001
Data Structures
Semester Project
Objectives:
• Exhibit the ability to implement the Data Structures learnt in the course to real world
problems.
• Choosing and analyzing the use of Data Structures to solve a problem.
• Designing Simple Algorithms that use a variety of Data Structures to solve a problem.
• Based on the knowledge of Data Structures taught in course, exhibit the ability to learn
and implement new structures by yourselves.





Chapter-1
Introduction
Smart Text Editor


1. INFORMATION CONSISTENCY
A text editor is a type of program used for editing plain text files. A plain text file is
represented and edited by showing all the characters as they are present in the file. The most
commonly used character set is ASCII, especially recently, as plain text files are more often
being used for programming and configuration, and less frequently for documentation (e.g.
detailed instructions, user guides) than in the past.
Smart Text Editor is a tool that allows its user to perform text editing, smart word
completion, saving and opening a text file.





2. PROJECT PURPOSE
To develop a smart text editor in C++ that is based on C++ platform and can be easily used
by all the users. If there are any changes required then a programmer can easily code and
see the changes and it most adaptable.




3. PROJECT FEATURES
Features of this project are described in the form of a story or primary user flow:
User creates text file and starts writing(typing) something to it. Just as in a typical text editor,
user types the words separated by spaces to form sentences which are separated by full stops etc.
At any point of time as user is typing a word, user is suggested words completion in following:




User typed word so far: ba Suggested Completions: bat, bar, ball
User typed word so far: bal Suggested Completions: ball, balm, bald
Basically, after writing each letter of the words, user is given suggestions(10 words at most) on
side of the screen, user moves to next word with pressing ‘/’ button and choses a word using ‘;’
button. For the purpose of avoiding any spelling mistakes, user must choose from given list of
words. (Dictionary is fixed from a list provided in a text file). Once writ, user can not move the
cursor backwards to edit his writing, can only append text in forward direction.
Once user presses the ‘=’ button, all the written text so far is converted into a compressed form
and save the encoding into a text file.
Later, if user wishes to open the file, encoded/compressed text is loaded and decompressed to
retrieve the original text, original text is shown to the user, and user may keep on typing further
and then save the file again in the same fashion as above.



Chapter-2
Functionalities
Major functionalities are listed as:
1. Typing Text
User should be able to type the text on the console.

2. Word Completion Suggestions
User should be presented with words completion options.




3. Compression of Text
This module allows the user to convert the text written in a compressed encoding which is
a representative of original text is many aspects with some added utilities like Compression
and Security:
o Compression:
The text is now reduced length and fewer characters and still contains all the
information in the original text.




As can be seen in above example, text has reduced from 40 characters to 10
characters now. Also note that one can easily recreate the original text from the
compressed text, just that one needs to know the rules for doing this.
o Security:
At times, the information is confidential and its security is an utmost priority. If
the medium to store the data or communicate isn’t reliable enough, we need to
still ensure the security. In such scenarios, text is stored or transferred in a form
that is only understood by the intended recipient. For others, it is just gibberish.
This falls under the domain of cyber-security(specifically cryptography) and has
many applications.









4. Saving the text to a file
Text to be saved to a file on local machine.




5. Loading the text from a file
Load the text from a pre-saved file.




6. Uncompressing of text
Uncompressing the text encoding to retrieve the actual text.




7. Continue Editing
User should be able to resume typing from where he left off.







Chapter-3
Implementation guidelines
Implementation should be thought of as implementing the functionalities. Let’s address them one
after another.



• Typing Text
You will be implementing a console-based module that helps user type a piece of texts. You
may wish to use vector strings, iterators and loops to achieve the purpose. It is only a
forward typing module; no backward editing is needed so should fair and simple.



• Word Completion Suggestions
In this module, you are to come up with a system that shows the user expected word
completions from the dictionary(Which is provided to you with the project).
For the purpose of words suggestions, you are to use trie trees or B-trees. An explanation is
provided in the explanatory video of the project attached herewith. Remember that after the
developing the Trie-tree over the dictionary, you will be storing the tree in order to use it
for word completion.



• Compression of text
In this module, you are to employ Huffman encoding as explained by the attached slides or
video. Remember that after the compression, you will be storing both the compressed text
and the compression tree. Otherwise, you won’t be able to recover the text in the import
stage later.



• Saving the text to a file
Compressed text (encoding) be saved to a .txt file on local machine. Along with saving the
compressed you must also store the compression tree in another file. You may use simple
file handling and write text to it.
• Loading the text from a file
You must allow the user to import the compressed text from previous saving as in above
step. Simple file handling is employed for this task.



• Uncompressing of text
System should load the Huffman compression tree to decompress the compressed text
encoding in order to recover the original text. The process is elaborated in the video and
slides attached here with.





• Continue Editing
User should be able to continue editing the text one the previous text is recovered in the
system. User may save and reload the file more than once.
