public class Profesor{
	private String numeroDePersonal;
	private String nombre;
	private String tipoDeContratacion;
	private Academia academia;
	//private Curso [] curso = new Curso[5];
	private String [] curso = new String[5];
	// esto puede cambiar	
	private int numsCurso = 0;

	public Profesor(){
	}

	public Profesor(String num, String nomb, String contra){
		this.numeroDePersonal = num;
		this.nombre = nomb;
		this.tipoDeContratacion = contra;
	}

	public String getNumeroDePersonal(){
		return numeroDePersonal;
	}

	public String getNombre(){
		return nombre;
	}

	public String getTipoDeContratacion(){
		return tipoDeContratacion;
	}

	public void setNumeroDePersonal(String num){
		this.numeroDePersonal = num;
	}

	public void setNombre(String nomb){
		this.nombre = nomb;
	}

	public void setTipoDeContratacion(String contra){
		this.tipoDeContratacion = contra;
	}
	
	public void addAcademia(Academia a){
		this.academia = a;
	}

	public Academia getAcademia(){
		return academia;
	}

	public void addCurso(String c){
		if (numCurso<5){
			this.curso[numCurso] = c;
			numCurso++;
		}
	}

	public String getCurso(int i)
	{
		return curso[i];
	}
}