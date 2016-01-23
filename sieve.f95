! sieve of eratosthenes algo implementation 

program sieve

    implicit none
    logical, allocatable :: isprime(:)
    integer           :: n, j, k, i
    character(len=50) :: carg
    
    call get_command_argument(1, carg, j, k)
    if ( k == 0 ) then
       read(unit=carg, fmt=*) n
    else
       print *, "Invalid command-line argument"
       stop
    end if
    if ( n < 2 ) then
       print *, "n must be at least 2"
       stop
    end if
    
    allocate(isprime(n))
    isprime = .true.
    isprime(1) = .false.
    
    do i=2, n, 1
       if (modulo(i,2)==0) then
          isprime(i) = .false.       
       else 
          if (isprime(i)) then 
             isprime(i) = .true.        
             if (REAL(i)<=sqrt(REAL(n))) then 
                k = 2
                do while (k*i<n)
                   isprime(k*(i)) = .false. 
                   k = k+1
                end do
             end if
          end if
       end if
    end do

    k=0
    do j = 1, n
       if ( isprime(j) ) then
          print "(i11, $)", j
          k = k + 1
          if ( modulo(k,7) == 0 ) print *
       end if
    end do
    if ( modulo(k,7) /= 0 ) print *
    
    deallocate(isprime)
    
  end program
