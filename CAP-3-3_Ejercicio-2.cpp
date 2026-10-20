// Ejercicio 2: Comparación y búsqueda de cadenas mediante punteros y aritmética de punteros en C++
// 
// Una empresa especializada en el manejo de datos de las redes sociales requiere que usted utilice 
// punteros y aritmética de punteros para implementar las siguientes funciones, esenciales para el 
// manejo eficiente de texto:
//     a) Una función llamada comparaCadenas que compare dos cadenas de caracteres str1 y str2. 
//     Esta función debe devolver un valor entero que indique si str1 es menor que, igual a o mayor que str2.
//     b) Una función llamada comparaSubcadenas que compare dos subcadenas de longitud n de las cadenas str1 
//     y str2. La función debe devolver un valor entero que indique si la subcadena de str1 es menor que, 
//     igual a o mayor que la subcadena de str2.
//     c) Una función denominada buscarPalabra que busque una palabra específica dentro de un texto. 
//     Esta función debe contar el número de ocurrencias de la palabra en el texto. 
//     (sugerencia: utilice la parte b))



#include <iostream>
using namespace std;
// Compara dos cadenas usando punteros
int comparaCadenas(char *str1, char *str2) {
    while(*str1 != '\0' && *str2 != '\0') {
        if(*str1 < *str2) {
            return -1; }
        if(*str1 > *str2) {
            return 1; }
        str1++;
        str2++; }
    if(*str1 == '\0' && *str2 == '\0') {
        return 0; }
    if(*str1 == '\0') {
        return -1; }
    return 1;
}
// Compara subcadenas de longitud n usando punteros
int comparaSubcadenas(char *str1, char *str2, int n) {
    for(int i = 0; i < n; i++) {
        if(*(str1+i) < *(str2+i)) {
            return -1; }
        if(*(str1+i) > *(str2+i)) {
            return 1; }
    }
    return 0;
}
// Busca una palabra dentro de un texto
int buscarPalabra(char *texto, char *palabra) {
    int contador = 0;
    while(*texto != '\0') {
        char *inicioTexto = texto;
        char *inicioPalabra = palabra;
        while(*inicioTexto != '\0' &&
              *inicioPalabra != '\0' &&
              *inicioTexto == *inicioPalabra) {
            inicioTexto++;
            inicioPalabra++; }
        if(*inicioPalabra == '\0') {
            contador++; }
        texto++; }
    return contador;
}
int main() {
    char str1[] = "abce";
    char str2[] = "abdh";
    cout << "comparaCadenas abce y abdh: " << comparaCadenas(str1,str2) << endl;
    char str3[] = "hola";
    char str4[] = "hola";
    cout << "comparaCadenas hola y hola: " << comparaCadenas(str3,str4) << endl;
    char str5[] = "wxyz";
    char str6[] = "abc";
    cout << "comparaCadenas wxyz y abc: " << comparaCadenas(str5,str6) << endl;
    cout << endl;
    cout << "comparaSubcadenas de longitud 3 de abce y abdh: " 
         << comparaSubcadenas(str1,str2,3) << endl;
    cout << "comparaSubcadenas de longitud 4 de hola y hola: " 
         << comparaSubcadenas(str3,str4,4) << endl;
    cout << "comparaSubcadenas de longitud 2 de wxyz y abc: " 
         << comparaSubcadenas(str5,str6,2) << endl;
    char texto[] =
    "El éxito es la suma de pequeños esfuerzos repetidos día tras día.";
    char palabra[] = "día";
    cout << endl;
    cout << "En la frase: \"" << texto << "\"" << endl;
    cout << "la palabra " << palabra << " aparece " 
         << buscarPalabra(texto,palabra) << " veces" << endl;
    return 0;
}