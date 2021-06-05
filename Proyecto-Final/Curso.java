public class Curso{

	private String nombre;
	private String nrc;
	private int bloque;
	private int  seccion;
	//private Profesor docente;
	private String docente;
	
	//private Estudiante[] alumno = new Estudiante[30];
	private String[] alumno = new String[30]; /// guardamos las matriculas
	private int numAlumno = 0;

	public Curso()
	{

	}

	public Curso(String nom, String nrc, int bloque, int seccion){
		this.nombre = nom;
		this.nrc = nrc;
		this.bloque = bloque;
		this.seccion = seccion;
	}

	public void setNombre(String a)
	{
		this.nombre = a;
	}

	public String getNombre()
	{
		return this.nombre;
	}

	public void setNrc(){
		this.nrc = nrc;
	}

	public void setBloque(){
		this.bloque = bloque;
	}

	public void setSeccion(){
		this.seccion = seccion;
	}

	public String getNrc(){
		return nrc;
	}

	public int getBloque(){
		return bloque;
	}

	public int getSeccion(){
		return seccion;
	}

	public void addDocente(String doc){
		this.docente = doc;
		
	}

	public void addEstudiante(String alumno){
		if (numAlumno < 30){
			this.alumno[numAlumno] = alumno;
			numAlumno++;
		}
		else
			System.out.println("No hay capacidad para más alumnos");
	}
	

	public int getNumAlumno(){
		return numAlumno;
	}

	public String getAlumno(int a){
		return alumno[a];
	}

	/// added getDocente()
	public String getDocente()
	{
		return this.docente;
	}

	/// added toString 
	public String toString()
	{

		String ans = "Curso: " + this.nombre + "\n";
		ans += "Bloque: " + String.valueOf((int)this.bloque) + "\n";
		ans += "Seccion: " + String.valueOf((int)this.seccion) + "\n";
		ans += "Docente: " + this.docente + "\n";
		ans += "Alumnos: " + String.valueOf((int)this.numAlumno) + "\n";
		ans += "Matriculas: \n";
		for(int c = 0 ; c<this.numAlumno; c++)
			ans += this.alumno[c] + "\n";
		return ans;



	}
}