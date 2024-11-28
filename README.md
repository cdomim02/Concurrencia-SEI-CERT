# Concurrencia-SEI-CERT
En este repositorio se analizará la regla de concurrencia "CON31-C/CON50-CPP. Do not destroy a mutex while it is locked" del SEI-CERT con la idea de ver como puede afectar un mal uso de la concurrencia en la seguridad de nuestro sistema

## Posibles vulnerabilidades
#### En esta sección veremos las posibles vulnerabilidades a las que nos enfrentaremos si no tenemos en cuenta esta regla.
    CWE-667: Improper Locking
    CWE-413: Improper Resource Locking
## Más información

## Referencias
- [CON-31-C: Do not destroy a mutex while it is locked](https://wiki.sei.cmu.edu/confluence/display/c/CON31-C.+Do+not+destroy+a+mutex+while+it+is+locked)
- [CERT: Mutex destroy while locked](https://help.klocwork.com/2024/en-us/reference/cert.conc.mutex.destroy_while_locked.htm)
- [CWE-413: Double-Checked Locking](https://cwe.mitre.org/data/definitions/413.html)
- [CWE-667: Shared Resource Synchronization Issues](https://cwe.mitre.org/data/definitions/667.html)
- [Programming using mutexes (IBM AIX 7.1)](https://www.ibm.com/docs/it/aix/7.1?topic=programming-using-mutexes)
- [Processing pragma omp critical (IBM z/OS 2.4.0)](https://www.ibm.com/docs/en/zos/2.4.0?topic=processing-pragma-omp-critical)
