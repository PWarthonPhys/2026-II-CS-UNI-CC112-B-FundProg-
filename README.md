# 2026-II-CS-UNI-CC112-B-FundProg-

En este repo irá todo lo visto en el curso "Fundamentos de Programación": 

//////////////////
Sincronizar nuevas ramas del repo del profesor:


# Ver remotos configurados   
git remote -v   
 
# Agregar el repo del profesor como upstream  
git remote add upstream https://github.com/ecuadros/2026-I-CS-UNI-CC112-B-FundProg.git   
 
# Traer cambios del upstream 
git fetch upstream   
 
# Ver ramas remotas disponibles
git branch -r   
 
# Crear y subir ramas locales desde upstream  
git checkout -b 01-main upstream/01-main
git push -u origin 01-main

git checkout -b 02-gitignore upstream/02-gitignore 
git push -u origin 02-gitignore   
 
////////////////
# código para  correr un programa en especifico 
 g++ -std=c++2b main.cpp -o main
 El main() debe ser muy pero muy pequeñito


 # forma segun gemini
 ## 2.Compilar el código fuente:
 Herramienta GCC.Escribe el siguiente comando para compilar tu archivo (reemplaza main.cpp por el nombre real de tu archivo):
 Bash
 ++ -o programa main.cpp
 Verificación: Si no muestra ningún mensaje de error, la terminal volverá a mostrar la ruta de tu carpeta y se habrá creado un archivo ejecutable llamado programa.
 ## 3.Ejecutar el programa:
 Ejecutable local.Ejecuta el archivo compilado con el siguiente comando:
 Bash
 ./programa
 Verificación: La salida o el resultado de tu programa se mostrará inmediatamente en la misma terminal.

///////////////

# git status
 Muestra el estado actual de tu directorio de trabajo. Úsalo constantemente para verificar qué archivos has modificado, eliminado o creado antes de subirlos.

# git add .
 Prepara (hace stage) todos los archivos modificados y nuevos para el próximo commit. Si prefieres ser selectivo y subir un solo archivo, utiliza git add nombre_del_archivo.cpp.

# git commit -m "Mensaje descriptivo"
 Guarda los archivos preparados en tu historial local. Asegúrate de que el mensaje sea claro sobre la modificación realizada (por ejemplo, "Se agregó la gestión de memoria dinámica para matrices").

# git push origin main
 Envía tus cambios confirmados localmente a tu repositorio remoto en GitHub. Si estás en una rama distinta a la principal, cambia main por el nombre de tu rama.

# git pull origin main
 Descarga los cambios más recientes del repositorio en GitHub a tu computadora local. Es una excelente práctica ejecutar este comando antes de empezar a programar cada día, especialmente si tu profesor sincroniza código o material nuevo en el repositorio remoto.

# git branch
 Muestra una lista de todas las ramas locales y resalta en cuál estás ubicado actualmente.

# git checkout -b nombre_de_rama (o git switch -c nombre_de_rama)
 Crea una rama nueva y te cambia a ella inmediatamente. Es fundamental para probar nuevos algoritmos sin arriesgar el código estable de tu rama principal.

//////

# Formato basico de un codigo

int sumar(int, int); //prototipo

int main() {
    int num1 = 7;
    int num2 = 4;

//Llamada
    int resultado = sumar(num1, num2);
    cout << "El resultado es: " <<
    resultado <<endl;
    }

// Definición , creo que tambien puede ir arriba, verificar

int sumar(int a, int b) {
    return a + b;}