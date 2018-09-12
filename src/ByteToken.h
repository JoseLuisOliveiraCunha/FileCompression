#pragma once

#include <string>

/**
 * holds information about a huffman coding token (1 byte), its respective code and how many times it was found in the
 * file
 */
class ByteToken
{
private:
	/**
	 * non null char. char representation of the the byte
	 */
	char key = 'a';

	/**
	 * positive long. number of times the byte was found in the file. default value of 1 since if the ByteToken was
	 * created its assumed its the first time it has been found in the file
	 */
	long count = 1;

	/**
	 * string representation of the binary code of the token
	 */
	std::string code = "";

public:
	/**
	 * default constructor for ByteToken, not explicitly used
	 */
	ByteToken();

	/**
	 * constructor for ByteToken. constructs a new ByteToken with a given byte represented as char
	 * @param key non null char. char representation of the the byte
	 */
    explicit ByteToken(char key);

	/**
	 * destructor for ByteToken
	 */
	~ByteToken();

	/**
	 * increments count by 1
	 */
	void increaseCount();

    /**
	 * assigns a new huffman code to the ByteToken in the form of a string
	 * @param code const reference to string representation of the binary code of the token
	 */
	void setCode(const std::string &code);

	/**
	 * returns char representation of the the byte
	 * @return non null char. char representation of the the byte
	 */
	char getKey();

	/**
	 * returns number of times the byte was found in the file
	 * @return positive long. number of times the byte was found in the file
	 */
	long getCount();

	/**
	 * returns the string representation of the binary code of the token
	 * @return string representation of the binary code of the token
	 */
	std::string getCode();
};

