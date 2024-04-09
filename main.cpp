#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::string;
using std::to_string;
using std::vector;

class GeraRelatorio
{
    virtual void salvaEmArquivo()
    {
    }
};

class Pessoa : public GeraRelatorio
{
public:
    const static int MAX_NUM = 10;
    const static int quant = 0;
    string getNome()
    {
        return this->nome;
    }

    void setNome(string nome)
    {
        this->nome = nome;
    }

    string getAnoDeEntrada()
    {
        return this->ano_entrada;
    }

    void setAnoDeEntrada(int anoDeEntrada)
    {
        this->ano_entrada = to_string(anoDeEntrada);
    }

    virtual void salvaEmArquivo()
    {
    }

private:
    string nome;
    string ano_entrada;
};

class Funcionario : public Pessoa
{
private:
    float salario;
    int siape;

public:
    inline static int num_func = 0;
    Funcionario(float salario)
    {
        this->siape = Funcionario::num_func;
        Funcionario::num_func += 1;
        this->salario = salario;
    }

    float getSalario()
    {
        return this->salario;
    }

    int getSiape()
    {
        return this->siape;
    }
};

class Aluno : public Pessoa
{
private:
    string curso;
    int matricula;

public:
    inline static int num_aluno = 0;

    Aluno(string nome, int ano_entrada, string curso)
    {
        this->setNome(nome);
        this->setAnoDeEntrada(ano_entrada);

        this->matricula = Aluno::num_aluno;
        Aluno::num_aluno += 1;

        this->curso = curso;
    }

    string getCurso()
    {
        return this->curso;
    }

    int getMatricula()
    {
        return this->matricula;
    }

    void salvaEmArquivo()
    {
        std::ofstream outfile;

        outfile.open("RelatórioAluno.txt", std::ios_base::app);
        if (outfile.is_open())
        {

            outfile << "Nome do Aluno: " << this->getNome() << "\n";
            outfile << "Ano de Entrada: " << this->getAnoDeEntrada() << "\n";
            outfile << "Matrícula: " << this->getMatricula() << "\n";
            outfile << "Curso: " << this->getCurso() << "\n";
            outfile << "***************** X *****************\n";
            outfile.close();

            std::cout << "Arquivo salvo" << std::endl;
        }
        else
        {
            std::cout << "Erro salvando arquivo." << std::endl;
        }
    }
};

class Secretario : public Funcionario
{
private:
    string setor;

public:
    Secretario(string nome, int anoDeEntrada, float salario, string setor) : Funcionario(salario)
    {
        this->setNome(nome);
        this->setAnoDeEntrada(anoDeEntrada);
        this->setor = setor;
    }
    string getSetor()
    {
        return setor;
    }

    void salvaEmArquivo()
    {
        std::ofstream outfile;

        outfile.open("RelatórioSecretario.txt", std::ios::app);
        if (outfile.is_open())
        {

            outfile << "Nome do Secretário: " << this->getNome() << "\n";
            outfile << "Ano de Entrada: " << this->getAnoDeEntrada() << "\n";
            outfile << "Siape: " << this->getSiape() << "\n";
            outfile << "Salário: " << this->getSalario() << "\n";
            outfile << "Setor: " << this->getSetor() << "\n";
            outfile << "****************** X *****************\n";
            outfile.close();

            std::cout << "Arquivo salvo" << std::endl;
        }
        else
        {
            std::cout << "Erro salvando arquivo." << std::endl;
        }
    }
};

class Professor : public Funcionario
{
private:
    string dpto;

public:
    Professor(string nome, int anoDeEntrada, float salario, string dpto) : Funcionario(salario)
    {
        this->setNome(nome);
        this->setAnoDeEntrada(anoDeEntrada);
        this->dpto = dpto;
    }

    string getDpto()
    {
        return this->dpto;
    }

    void salvaEmArquivo()
    {
        std::ofstream outfile;

        outfile.open("RelatórioProfessor.txt", std::ios::app);
        if (outfile.is_open())
        {

            outfile << "Nome do Professor: " << this->getNome() << "\n";
            outfile << "Ano de Entrada: " << this->getAnoDeEntrada() << "\n";
            outfile << "Siape: " << this->getSiape() << "\n";
            outfile << "Salário: " << this->getSalario() << "\n";
            outfile << "Curso: " << this->getDpto() << "\n";
            outfile << "****************** X *****************\n";
            outfile.close();

            std::cout << "Arquivo salvo" << std::endl;
        }
        else
        {
            std::cout << "Erro salvando arquivo." << std::endl;
        }
    }
};

int main(int, char **)
{
    vector<Pessoa *> pessoas = {};

    pessoas.push_back(new Secretario("Sheila", 2010, 5000.0, "secPEB"));
    pessoas.push_back(new Aluno("Carlos", 2022, "Computação"));
    pessoas.push_back(new Professor("Marcelo", 2016, 400.0, "PEB"));
    pessoas.push_back(new Aluno("Márcio", 2020, "Pedagogia"));
    pessoas.push_back(new Secretario("André", 2014, 7000.0, "Biblioteca"));
    pessoas.push_back(new Professor("Leila", 2018, 4000.0, "PCH"));
    pessoas.push_back(new Secretario("Letícia", 2019, 4500.0, "secPCH"));
    pessoas.push_back(new Aluno("Lucas", 2019, "Pedagogia"));
    pessoas.push_back(new Professor("Thales", 2018, 7000.0, "PEB"));
    pessoas.push_back(new Professor("Luiza", 2013, 10000.0, "PCB"));
    pessoas.push_back(new Aluno("Thales", 2020, "Matemática"));

    for (auto &&pessoa : pessoas)
    {
        pessoa->salvaEmArquivo();
    }
}
