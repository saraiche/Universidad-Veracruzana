public class Estudiante{
	private String matricula;
	private String nombre;
	private Curso[] curso= new Curso[6];
	private int numCurso = 0;
	
	public Estudiante(){
	}

	public Estudiante(String mat, String nomb){
		this.matricula = mat;
		this.nombre = nomb;
	}

	public void setMatricula(String mat){
		this.matricula = mat;
	}

	public String getMatricula(){
		return matricula;
	}

	public void setNombre(String nomb){
		this.nombre = nomb;
	}

	public String getNombre(){
		return nombre;
	}

	public void addCurso(Curso curso){
		if (numCurso < 6){
			this.curso[numCurso] = curso;
			numCurso++;
		}
		else
			System.out.println("No hay capacidad para más cursos");
	}
	
	public Curso getCurso(int c){
		return curso[c];
	}

	public int getNumCurso(){
		return numCurso;
	}
}