public class ExperienciaEducativa{
	private String clave;
	private int totalDeCreditos;
	//private Curso[] curso = new Curso[1]; /// aqui puede haber más de uno ? 
	private Curso curso;
	///private int numCurso = 0; nno es necesario si solo hay 1 

	public ExperienciaEducativa(){
	}

	public ExperienciaEducativa(String c, int tC){
		this.clave = c;
		this.totalDeCreditos = tC;
	}

	public void setClave(String c){
		this.clave = c;
	}

	public String getClave(){
		return clave;
	}

	public void setTotalDeCreditos(int tC){
		this.totalDeCreditos = tC;
	}

	public int getTotalDeCreditos(){
		return totalDeCreditos;
	}

	public void addCurso(Curso c){
		/*if (numCurso<2){
			this.curso[numCurso] = c;
			numCurso++;
		}
		*/
		this.curso = c;
	}

	// added get curso 
	public Curso getCurso()
	{
		return this.curso;
	}
	/*
	no es necesario si solo hay 1 
	public int getNumCurso(){
		return numCurso;
	}*/
}