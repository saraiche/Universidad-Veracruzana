public class ExperienciaEducativa{
	private String clave;
	private int totalDeCreditos;
	private Curso[] curso = new Curso[1];
	private numCurso = 0;

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
		this.clave = c;
	}

	public String getTotalDeCreditos(){
		return totalDeCreditos;
	}

	public void addCurso(Curso c){
		if (numCurso<2){
			this.curso[numCurso] = c;
			numCurso++;
		}
	}
	
	public int getNumCurso(){
		return numCurso;
	}
}