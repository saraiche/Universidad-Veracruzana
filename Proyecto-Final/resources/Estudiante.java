package resources; // lo empaquetamos 

public class Estudiante extends Template {
	private String matricula;
	private String nombre;
	///private Curso[] curso= new Curso[6];
	private String[] curso = new String[8];
	private int numCreditos = 0 ; /// difiere
	private int numCurso = 0;
 //// limite 356
	
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

	public void addCurso(String curso){
		if (numCurso < 8){
			this.curso[this.numCurso] = curso;
			numCurso++;
		}
		else
			System.err.println("No hay capacidad para más cursos");
	}
	
	public String getCurso(int c){
		return curso[c];
	}

	public int getNumCurso(){
		return numCurso;
	}

	/// more 
	public int getNumCreditos()
	{
		return this.numCreditos;
	}

	public void setNumCreditos(int a )
	{
		this.numCreditos = a;
	}

	public void setNumCurso(int a )
	{
		this.numCurso = a;
	}


	//// =========== Estudiante tiene toString ============
	public String toString()
	{
		String ans = "\n\tEstudiantes\n";
		ans += "Nombre: " + this.nombre + "\n";
		ans += "Matricula: " + this.matricula + "\n";
		ans += "Creditos: " + String.valueOf(this.numCreditos) + "\n";
		ans += "Cursos: " + String.valueOf(this.numCurso) + "\n";
		for(int c = 0 ; c<this.numCurso; c++)
			ans += this.curso[c] + " ";
		return ans;
	}
}