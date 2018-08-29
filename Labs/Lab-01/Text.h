#ifndef TEXT_H
	#define TEXT_H

	struct Text {
		const char * textArray;
			//A character string holding my “String”
		int size;
			//The size of my string
	};

	Text * createText(const char* text);

	void destroyText(Text* myText);

	void displayText(Text* myText);

	const char* getText(Text* myText);

	int getLength(Text* myText);


#endif /* TEXT_H */
