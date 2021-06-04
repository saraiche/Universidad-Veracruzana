public class Curso{
	private String nrc;
	private int bloque;
	private int  seccion;
	private Profesor docente;
	private Estudiante[] alumno = new Estudiante[30];
	private int numAlumno = 0;

	public Curso(){
	}

	public Curso(String nrc, int bloque, int seccion){
		this.nrc = nrc;
		this.bloque = bloque;
		this.seccion = seccion;
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

	public void addDocente(Profesor doc){
		
	}

	public void addEstudiante(Estudiante alumno){
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

	public Estudiante getAlumno(int a){
		return alumno[a];
	}
}