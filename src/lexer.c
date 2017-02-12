/* Generated by re2c 0.14.3 on Sun Feb 12 17:20:11 2017 */
/**

	MultiMarkdown 6 -- Lightweight markup processor to produce HTML, LaTeX, and more.

	@file lexer.re

	@brief Description of the regular expressions used to define tokens, 
	used by re2c to create a lexer/tokenizer.


	@author	Fletcher T. Penney
	@bug	

**/

/*

	Copyright © 2016 - 2017 Fletcher T. Penney.


	The `MultiMarkdown 6` project is released under the MIT License..
	
	GLibFacade.c and GLibFacade.h are from the MultiMarkdown v4 project:
	
		https://github.com/fletcher/MultiMarkdown-4/
	
	MMD 4 is released under both the MIT License and GPL.
	
	
	CuTest is released under the zlib/libpng license. See CuTest.c for the text
	of the license.
	
	
	## The MIT License ##
	
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.

*/

#include "lexer.h"
#include "libMultiMarkdown.h"
#include "parser.h"


// Basic scanner struct

#define YYCTYPE		char
#define YYCURSOR	s->cur
#define YYMARKER	s->ptr
#define YYCTXMARKER	s->ctx


int scan(Scanner * s, const char * stop) {

	scan:

	if (s->cur >= stop) {
		return 0;
	}

	s->start = s->cur;

	
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;

	yych = *YYCURSOR;
	switch (yych) {
	case '\t':	goto yy42;
	case '\n':	goto yy48;
	case '\r':	goto yy50;
	case ' ':	goto yy44;
	case '!':	goto yy18;
	case '"':	goto yy26;
	case '#':	goto yy45;
	case '$':	goto yy38;
	case '&':	goto yy33;
	case '\'':	goto yy28;
	case '(':	goto yy19;
	case ')':	goto yy21;
	case '*':	goto yy51;
	case '+':	goto yy4;
	case '-':	goto yy6;
	case '.':	goto yy30;
	case '/':	goto yy35;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy47;
	case ':':	goto yy31;
	case '<':	goto yy8;
	case '=':	goto yy12;
	case '>':	goto yy23;
	case '[':	goto yy14;
	case '\\':	goto yy37;
	case ']':	goto yy16;
	case '^':	goto yy40;
	case '_':	goto yy53;
	case '`':	goto yy55;
	case '{':	goto yy2;
	case '|':	goto yy57;
	case '}':	goto yy25;
	case '~':	goto yy10;
	default:	goto yy59;
	}
yy2:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '+':	goto yy257;
	case '-':	goto yy256;
	case '=':	goto yy253;
	case '>':	goto yy255;
	case '{':	goto yy251;
	case '~':	goto yy254;
	default:	goto yy3;
	}
yy3:
	{ goto scan; }
yy4:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '+':	goto yy248;
	default:	goto yy5;
	}
yy5:
	{ return PLUS; }
yy6:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '-':	goto yy242;
	default:	goto yy7;
	}
yy7:
	{ return DASH_N; }
yy8:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '<':	goto yy239;
	default:	goto yy9;
	}
yy9:
	{ return ANGLE_LEFT; }
yy10:
	yyaccept = 3;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '>':	goto yy235;
	case '~':	goto yy234;
	default:	goto yy11;
	}
yy11:
	{ return SUBSCRIPT; }
yy12:
	yyaccept = 4;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '=':	goto yy231;
	default:	goto yy13;
	}
yy13:
	{ return EQUAL; }
yy14:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '#':	goto yy227;
	case '%':	goto yy225;
	case '^':	goto yy229;
	default:	goto yy15;
	}
yy15:
	{ return BRACKET_LEFT; }
yy16:
	++YYCURSOR;
	{ return BRACKET_RIGHT; }
yy18:
	yych = *++YYCURSOR;
	switch (yych) {
	case '[':	goto yy223;
	default:	goto yy3;
	}
yy19:
	++YYCURSOR;
	{ return PAREN_LEFT; }
yy21:
	++YYCURSOR;
	{ return PAREN_RIGHT; }
yy23:
	++YYCURSOR;
	{ return ANGLE_RIGHT; }
yy25:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy221;
	default:	goto yy3;
	}
yy26:
	++YYCURSOR;
	{ return QUOTE_DOUBLE; }
yy28:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '\'':	goto yy219;
	default:	goto yy29;
	}
yy29:
	{ return QUOTE_SINGLE; }
yy30:
	YYCTXMARKER = YYCURSOR + 1;
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\t':	goto yy209;
	case '\n':	goto yy206;
	case '\r':	goto yy208;
	case ' ':	goto yy211;
	case '.':	goto yy212;
	default:	goto yy3;
	}
yy31:
	++YYCURSOR;
	{ return COLON; }
yy33:
	yyaccept = 5;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'A':
	case 'a':	goto yy201;
	default:	goto yy34;
	}
yy34:
	{ return AMPERSAND; }
yy35:
	++YYCURSOR;
	{ return SLASH; }
yy37:
	yych = *++YYCURSOR;
	switch (yych) {
	case ' ':	goto yy129;
	case '!':	goto yy189;
	case '"':	goto yy179;
	case '#':	goto yy159;
	case '$':	goto yy157;
	case '%':	goto yy155;
	case '&':	goto yy143;
	case '\'':	goto yy177;
	case '(':	goto yy171;
	case ')':	goto yy169;
	case '*':	goto yy135;
	case '+':	goto yy153;
	case ',':	goto yy185;
	case '-':	goto yy151;
	case '.':	goto yy191;
	case '/':	goto yy139;
	case ':':	goto yy181;
	case ';':	goto yy183;
	case '<':	goto yy147;
	case '=':	goto yy149;
	case '>':	goto yy145;
	case '?':	goto yy187;
	case '@':	goto yy141;
	case '[':	goto yy163;
	case '\\':	goto yy127;
	case ']':	goto yy161;
	case '^':	goto yy137;
	case '_':	goto yy133;
	case '`':	goto yy175;
	case '{':	goto yy167;
	case '|':	goto yy131;
	case '}':	goto yy165;
	case '~':	goto yy173;
	default:	goto yy3;
	}
yy38:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '$':	goto yy125;
	default:	goto yy39;
	}
yy39:
	{ return MATH_DOLLAR_SINGLE; }
yy40:
	++YYCURSOR;
	{ return SUPERSCRIPT; }
yy42:
	++YYCURSOR;
	{ return INDENT_TAB; }
yy44:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy48;
	case '\r':	goto yy116;
	case ' ':	goto yy114;
	default:	goto yy3;
	}
yy45:
	YYCTXMARKER = YYCURSOR + 1;
	yyaccept = 6;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy75;
	case '#':	goto yy73;
	default:	goto yy46;
	}
yy46:
	{ return TEXT_HASH; }
yy47:
	YYCTXMARKER = YYCURSOR + 1;
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '.':	goto yy64;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy66;
	default:	goto yy3;
	}
yy48:
	++YYCURSOR;
yy49:
	{ return TEXT_NL; }
yy50:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy48;
	default:	goto yy49;
	}
yy51:
	++YYCURSOR;
	{ return STAR; }
yy53:
	++YYCURSOR;
	{ return UL; }
yy55:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy63;
yy56:
	{ return BACKTICK; }
yy57:
	++YYCURSOR;
	yych = *YYCURSOR;
	goto yy61;
yy58:
	{ return PIPE; }
yy59:
	yych = *++YYCURSOR;
	goto yy3;
yy60:
	++YYCURSOR;
	yych = *YYCURSOR;
yy61:
	switch (yych) {
	case '|':	goto yy60;
	default:	goto yy58;
	}
yy62:
	++YYCURSOR;
	yych = *YYCURSOR;
yy63:
	switch (yych) {
	case '`':	goto yy62;
	default:	goto yy56;
	}
yy64:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case ' ':	goto yy71;
	case '\n':	goto yy68;
	case '\r':	goto yy70;
	default:	goto yy65;
	}
yy65:
	YYCURSOR = YYMARKER;
	switch (yyaccept) {
	case 0: 	goto yy3;
	case 1: 	goto yy5;
	case 2: 	goto yy9;
	case 3: 	goto yy11;
	case 4: 	goto yy13;
	case 5: 	goto yy34;
	case 6: 	goto yy46;
	case 7: 	goto yy122;
	case 8: 	goto yy207;
	default:	goto yy252;
	}
yy66:
	YYCTXMARKER = YYCURSOR + 1;
	++YYCURSOR;
	yych = *YYCURSOR;
	switch (yych) {
	case '.':	goto yy64;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy66;
	default:	goto yy65;
	}
yy68:
	++YYCURSOR;
yy69:
	YYCURSOR = YYCTXMARKER;
	{ return TEXT_NUMBER_POSS_LIST; }
yy70:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy68;
	default:	goto yy69;
	}
yy71:
	++YYCURSOR;
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case ' ':	goto yy71;
	default:	goto yy69;
	}
yy73:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy81;
	case '#':	goto yy86;
	default:	goto yy65;
	}
yy74:
	++YYCURSOR;
	yych = *YYCURSOR;
yy75:
	switch (yych) {
	case '\t':
	case ' ':	goto yy74;
	case '\n':	goto yy77;
	case '\r':	goto yy79;
	default:	goto yy76;
	}
yy76:
	{ return HASH1; }
yy77:
	++YYCURSOR;
yy78:
	YYCURSOR = YYCTXMARKER;
	{ return HASH1; }
yy79:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy77;
	default:	goto yy78;
	}
yy80:
	++YYCURSOR;
	yych = *YYCURSOR;
yy81:
	switch (yych) {
	case '\t':
	case ' ':	goto yy80;
	case '\n':	goto yy83;
	case '\r':	goto yy85;
	default:	goto yy82;
	}
yy82:
	{ return HASH2; }
yy83:
	++YYCURSOR;
yy84:
	YYCURSOR = YYCTXMARKER;
	{ return HASH2; }
yy85:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy83;
	default:	goto yy84;
	}
yy86:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy89;
	case '#':	goto yy87;
	default:	goto yy65;
	}
yy87:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy95;
	case '#':	goto yy100;
	default:	goto yy65;
	}
yy88:
	++YYCURSOR;
	yych = *YYCURSOR;
yy89:
	switch (yych) {
	case '\t':
	case ' ':	goto yy88;
	case '\n':	goto yy91;
	case '\r':	goto yy93;
	default:	goto yy90;
	}
yy90:
	{ return HASH3; }
yy91:
	++YYCURSOR;
yy92:
	YYCURSOR = YYCTXMARKER;
	{ return HASH3; }
yy93:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy91;
	default:	goto yy92;
	}
yy94:
	++YYCURSOR;
	yych = *YYCURSOR;
yy95:
	switch (yych) {
	case '\t':
	case ' ':	goto yy94;
	case '\n':	goto yy97;
	case '\r':	goto yy99;
	default:	goto yy96;
	}
yy96:
	{ return HASH4; }
yy97:
	++YYCURSOR;
yy98:
	YYCURSOR = YYCTXMARKER;
	{ return HASH4; }
yy99:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy97;
	default:	goto yy98;
	}
yy100:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy103;
	case '#':	goto yy101;
	default:	goto yy65;
	}
yy101:
	YYCTXMARKER = YYCURSOR + 1;
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy109;
	default:	goto yy65;
	}
yy102:
	++YYCURSOR;
	yych = *YYCURSOR;
yy103:
	switch (yych) {
	case '\t':
	case ' ':	goto yy102;
	case '\n':	goto yy105;
	case '\r':	goto yy107;
	default:	goto yy104;
	}
yy104:
	{ return HASH5; }
yy105:
	++YYCURSOR;
yy106:
	YYCURSOR = YYCTXMARKER;
	{ return HASH5; }
yy107:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy105;
	default:	goto yy106;
	}
yy108:
	++YYCURSOR;
	yych = *YYCURSOR;
yy109:
	switch (yych) {
	case '\t':
	case ' ':	goto yy108;
	case '\n':	goto yy111;
	case '\r':	goto yy113;
	default:	goto yy110;
	}
yy110:
	{ return HASH6; }
yy111:
	++YYCURSOR;
yy112:
	YYCURSOR = YYCTXMARKER;
	{ return HASH6; }
yy113:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy111;
	default:	goto yy112;
	}
yy114:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '\n':	goto yy118;
	case '\r':	goto yy120;
	case ' ':	goto yy117;
	default:	goto yy115;
	}
yy115:
	{ return NON_INDENT_SPACE; }
yy116:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy48;
	default:	goto yy49;
	}
yy117:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy118;
	case '\r':	goto yy120;
	case ' ':	goto yy121;
	default:	goto yy115;
	}
yy118:
	++YYCURSOR;
yy119:
	{ return TEXT_LINEBREAK; }
yy120:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy118;
	default:	goto yy119;
	}
yy121:
	yyaccept = 7;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '\n':	goto yy118;
	case '\r':	goto yy120;
	case ' ':	goto yy123;
	default:	goto yy122;
	}
yy122:
	{ return INDENT_SPACE; }
yy123:
	++YYCURSOR;
	yych = *YYCURSOR;
	switch (yych) {
	case '\n':	goto yy118;
	case '\r':	goto yy120;
	case ' ':	goto yy123;
	default:	goto yy65;
	}
yy125:
	++YYCURSOR;
	{ return MATH_DOLLAR_DOUBLE; }
yy127:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '(':	goto yy193;
	case ')':	goto yy195;
	case '[':	goto yy197;
	case ']':	goto yy199;
	default:	goto yy128;
	}
yy128:
	{ return ESCAPED_CHARACTER; }
yy129:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy131:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy133:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy135:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy137:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy139:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy141:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy143:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy145:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy147:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy149:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy151:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy153:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy155:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy157:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy159:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy161:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy163:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy165:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy167:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy169:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy171:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy173:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy175:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy177:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy179:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy181:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy183:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy185:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy187:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy189:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy191:
	++YYCURSOR;
	{ return ESCAPED_CHARACTER; }
yy193:
	++YYCURSOR;
	{ return MATH_PAREN_OPEN; }
yy195:
	++YYCURSOR;
	{ return MATH_PAREN_CLOSE; }
yy197:
	++YYCURSOR;
	{ return MATH_BRACKET_OPEN; }
yy199:
	++YYCURSOR;
	{ return MATH_BRACKET_CLOSE; }
yy201:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'M':
	case 'm':	goto yy202;
	default:	goto yy65;
	}
yy202:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'P':
	case 'p':	goto yy203;
	default:	goto yy65;
	}
yy203:
	yych = *++YYCURSOR;
	switch (yych) {
	case ';':	goto yy204;
	default:	goto yy65;
	}
yy204:
	++YYCURSOR;
	{ return AMPERSAND_LONG; }
yy206:
	++YYCURSOR;
yy207:
	YYCURSOR = YYCTXMARKER;
	{ return TEXT_PERIOD; }
yy208:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\n':	goto yy206;
	default:	goto yy207;
	}
yy209:
	++YYCURSOR;
	yych = *YYCURSOR;
yy210:
	switch (yych) {
	case '\t':
	case ' ':	goto yy209;
	default:	goto yy207;
	}
yy211:
	yyaccept = 8;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '.':	goto yy215;
	default:	goto yy210;
	}
yy212:
	yych = *++YYCURSOR;
	switch (yych) {
	case '.':	goto yy213;
	default:	goto yy65;
	}
yy213:
	++YYCURSOR;
	{ return ELLIPSIS; }
yy215:
	yych = *++YYCURSOR;
	switch (yych) {
	case ' ':	goto yy216;
	default:	goto yy65;
	}
yy216:
	yych = *++YYCURSOR;
	switch (yych) {
	case '.':	goto yy217;
	default:	goto yy65;
	}
yy217:
	++YYCURSOR;
	{ return ELLIPSIS; }
yy219:
	++YYCURSOR;
	{ return QUOTE_RIGHT_ALT; }
yy221:
	++YYCURSOR;
	{ return BRACE_DOUBLE_RIGHT; }
yy223:
	++YYCURSOR;
	{ return BRACKET_IMAGE_LEFT; }
yy225:
	++YYCURSOR;
	{ return BRACKET_VARIABLE_LEFT; }
yy227:
	++YYCURSOR;
	{ return BRACKET_CITATION_LEFT; }
yy229:
	++YYCURSOR;
	{ return BRACKET_FOOTNOTE_LEFT; }
yy231:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy232;
	default:	goto yy65;
	}
yy232:
	++YYCURSOR;
	{ return CRITIC_HI_CLOSE; }
yy234:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy237;
	default:	goto yy65;
	}
yy235:
	++YYCURSOR;
	{ return CRITIC_SUB_DIV; }
yy237:
	++YYCURSOR;
	{ return CRITIC_SUB_CLOSE; }
yy239:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy240;
	default:	goto yy65;
	}
yy240:
	++YYCURSOR;
	{ return CRITIC_COM_CLOSE; }
yy242:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case '-':	goto yy246;
	case '}':	goto yy244;
	default:	goto yy243;
	}
yy243:
	{ return DASH_N; }
yy244:
	++YYCURSOR;
	{ return CRITIC_DEL_CLOSE; }
yy246:
	++YYCURSOR;
	{ return DASH_M; }
yy248:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy249;
	default:	goto yy65;
	}
yy249:
	++YYCURSOR;
	{ return CRITIC_ADD_CLOSE; }
yy251:
	yyaccept = 9;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'T':	goto yy268;
	default:	goto yy252;
	}
yy252:
	{ return BRACE_DOUBLE_LEFT; }
yy253:
	yych = *++YYCURSOR;
	switch (yych) {
	case '=':	goto yy266;
	default:	goto yy65;
	}
yy254:
	yych = *++YYCURSOR;
	switch (yych) {
	case '~':	goto yy264;
	default:	goto yy65;
	}
yy255:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy262;
	default:	goto yy65;
	}
yy256:
	yych = *++YYCURSOR;
	switch (yych) {
	case '-':	goto yy260;
	default:	goto yy65;
	}
yy257:
	yych = *++YYCURSOR;
	switch (yych) {
	case '+':	goto yy258;
	default:	goto yy65;
	}
yy258:
	++YYCURSOR;
	{ return CRITIC_ADD_OPEN; }
yy260:
	++YYCURSOR;
	{ return CRITIC_DEL_OPEN; }
yy262:
	++YYCURSOR;
	{ return CRITIC_COM_OPEN; }
yy264:
	++YYCURSOR;
	{ return CRITIC_SUB_OPEN; }
yy266:
	++YYCURSOR;
	{ return CRITIC_HI_OPEN; }
yy268:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'O':	goto yy269;
	default:	goto yy65;
	}
yy269:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'C':	goto yy270;
	default:	goto yy65;
	}
yy270:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy271;
	default:	goto yy65;
	}
yy271:
	yych = *++YYCURSOR;
	switch (yych) {
	case '}':	goto yy272;
	default:	goto yy65;
	}
yy272:
	++YYCURSOR;
	{ return TOC; }
}

}
