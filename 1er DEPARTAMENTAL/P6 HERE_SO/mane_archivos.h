#ifndef MANE_ARCHIVOS_H
#define MANE_ARCHIVOS_H
#define OUTPUT_DIR ""

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class TeeBuffer : public streambuf 
{
public:
    TeeBuffer(streambuf* terminal, streambuf* capture)
        : terminal_(terminal), capture_(capture) {}

protected:

    int overflow(int c) override
		{
	        if (c == EOF) return EOF;
	        if (terminal_->sputc(c) == EOF) return EOF;
	        if (capture_->sputc(c) == EOF) return EOF;
	        return c;
	    }

	streamsize xsputn(const char* s, streamsize n) override 
		{
	        terminal_->sputn(s, n);
	        capture_->sputn(s, n);
	        return n;
	    }

private:
    streambuf* terminal_;
    streambuf* capture_;
};

class OutputCapture 
{
public:
    OutputCapture() 
	{
        tee_ = new TeeBuffer(cout.rdbuf(), capture_.rdbuf());
        original_ = cout.rdbuf(tee_);
    }
    ~OutputCapture() 
	{
        cout.rdbuf(original_);
        delete tee_;
    }
    string get() const { return capture_.str(); }

private:
    ostringstream capture_;
    TeeBuffer*         tee_;
    streambuf*    original_;
};

inline void writeJSON(const string& programa, const string& salida) {
    string path = string(OUTPUT_DIR) + "out.json";
    string escaped;
    for (size_t i = 0; i < salida.length(); ++i) {
        char c = salida[i];
        if (c == '"') escaped += "\\\"";
        else if (c == '\\') escaped += "\\\\";
        else if (c == '\n') escaped += "\\n";
        else if (c == '\r') escaped += "\\r";
        else if (c == '\t') escaped += "\\t";
        else escaped += c;
    }
    std::ofstream f(path.c_str(), std::ios::trunc);
    f << "[\n"
      << "  {\n"
      << "    \"programa\": \"" << programa << "\",\n"
      << "    \"salida\": \"" << escaped << "\"\n"
      << "  }\n"
      << "]\n";
}

inline void writeXML(const string& programa, const string& salida) 
{
    string path = std::string(OUTPUT_DIR) + "out.xml";
    string escaped;
    for (size_t i = 0; i < salida.length(); ++i) 
	{
        char c = salida[i];
        if (c == '&') escaped += "&amp;";
        else if (c == '<') escaped += "&lt;";
        else if (c == '>') escaped += "&gt;";
        else if (c == '"') escaped += "&quot;";
        else if (c == '\'') escaped += "&apos;";
        else escaped += c;
    }
    ofstream f(path.c_str(), std::ios::trunc);
    f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
      << "<programas>\n"
      << "  <entrada>\n"
      << "    <programa>" << programa << "</programa>\n"
      << "    <salida>" << escaped << "</salida>\n"
      << "  </entrada>\n"
      << "</programas>\n";
}

inline void writeCSV(const string& programa, const string& salida) 
{
    string path = std::string(OUTPUT_DIR) + "out.csv";
    string escaped;
    for (size_t i = 0; i < salida.length(); ++i) 
	{
        char c = salida[i];
        escaped += (c == '"') ? string("\"\"") : string(1, c);
    }
    ofstream f(path.c_str(), std::ios::trunc);
    f << "programa,salida\n"
      << "\"" << programa << "\",\"" << escaped << "\"\n";
}

inline void writeTXT(const string& programa, const string& salida) 
{
    string path = string(OUTPUT_DIR) + "out.txt";
    ofstream f(path.c_str(), std::ios::trunc);
f << "+--------------------------------------------------+\n"
  << "| PROGRAMA: " << programa << "\n"
  << "+--------------------------------------------------+\n"
  << "| SALIDA: \n"
  << "| " << salida << "\n"
  << "+--------------------------------------------------+\n";
}

inline void writeAllOutputs(const string& programa, const string& salida) 
{
    writeJSON(programa, salida);
    writeXML(programa, salida);
    writeCSV(programa, salida);
    writeTXT(programa, salida);
}
#endif 

