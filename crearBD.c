#include <stdio.h>
#include <sqlite3.h>

int main(void){
   sqlite3 *db;
   char *err_msg=0;
   int rc=sqlite3_open("test.db", &db);

   if(rc!=SQLITE_OK){
      fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
   
      return 1;
   }
   char *sql="DROP TABLE IF EXISTS Registro;"
             "CREATE TABLE Registro(IdRegistro INT PRIMARY KEY AUTOINCREMENT, NombreReg VARCHAR, Descripcion VARCHAR, 
                                    Subida BOOLEAN, Bajada BOOLEAN, Velocida DOUBLE, Tamaño DOUBLE, Tipo VARCHAR);";

   char *sql="DROP TABLE IF EXISTS Fecha;"
             "CREATE TABLE Fecha(fechaReg DATE, 
                                 ID_Registro INT,
                                 FOREING KEY(ID_Registro)REFERENCES Registro(IdRegistro));";

   char *sql="DROP TABLE IF EXISTS Usuario;"
             "CREATE TABLE Usuario(IdUsuario INT PRIMARY KEY AUTOINCREMENT,
                                   NombreUs VARCHAR,
                                   Id_Registro INT,
                                   FOREING KEY (Id_Registro) REFERENCES Registro(IdRegistro));";


   rc=sqlite3_exec(db, sql, 0, 0, &err_msg);
   if(rc!=SQLITE_OK){
      fprintf(stderr, "SQL error: %s\n", err_msg);
      sqlite3_free(err_msg);
      sqlite3_close(db); 

      return 1;
   }
   
   sqlite3_close(db);

}
