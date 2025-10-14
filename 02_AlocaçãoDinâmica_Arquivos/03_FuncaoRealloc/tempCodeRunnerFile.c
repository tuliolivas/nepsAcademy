p = (int*) calloc(n, sizeof(int));
    
    if (p != NULL)
    {
        printf("Vetor alocado com sucesso para %d elementos.\n", n);
        printf("Endereco inicial do vetor na memoria: %p\n", (void *)p);
    }

    else
    {
        fprintf(stderr, "Falha ao alocar memoria.\n");
        return EXIT_FAILURE;
    }