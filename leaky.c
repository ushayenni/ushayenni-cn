void main()
{
        int bucketSize, outputRate, n, incoming;
        int stored = 0;
        printf("=== Leaky Bucket Algorithm Simulation ===\n");
        printf("Enter bucket capacity (in packets): ");
        scanf("%d", &bucketSize);
        printf("Enter output rate (packats per second): ");
        scanf("%d", &outputRate);
        printf("Enter number of incoming packets (time slots): ");
        scanf("%d", &n);
        for(int i = 1; i<=n;i++)
        {
                printf("\nTime %d: Enter number of incoming packets: ",i);
                scanf("%d",&incoming);
                printf("Incoming packets: %d\n", incoming);
                if(incoming + stored > bucketSize)
                {
                        int dropped = (incoming + stored) - bucketSize;
                        stored = bucketSize;
                        printf("Bucket overflow! Dropped packets: %d\n", dropped);
                }
                else
                        stored=stored+incoming;
                if ( stored > outputRate)
                {
                        stored=stored-outputRate;
                        printf("Transmitted: %d | Packets left in bucket: %d\n",outputRate,stored);
                }
                else
                {
                        printf("Transmitted: %d | Packets left in bucket: 0\n", stored);
                        stored = 0;
                }
        }
        while  (stored > 0) {
                if (stored > outputRate)
                {
                        stored=stored-outputRate;
                        printf("\nTrasmitted: %d | Packets left in bucket: %d\n", outputRate, stored);
                }
                else
                {
                        printf("Transmitted: %d | Packets left in bucket: 0\n", stored);
                        stored = 0;
                }
        }
        printf("\nAll packets trasmitted successfully!\n");
}

