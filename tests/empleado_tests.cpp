#include <gtest/gtest.h>
#include "../src/empleado.h"
#include "../src/empleadoNomina.h"
#include "../src/empleadoPorHora.h"

namespace {

    TEST(Empleado_Tests, Test_Obtener_Lista_Empleados){
        // arrange:
        int idEmpleadoNuevo = 8; 
        string nombreEmpleadoNuevo = "Ever"; 
        string apellidoEmpleadoNuevo = "Duarte"; 
        string emailEmpleadoNuevo = "duarte95gmail.com";
        int tipoEmpleadoNuevo = 1;  
        int idSupervisorEmpleadoNuevo = 1;

        EmpleadoNomina *empNomina = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    
        int idSupervisor = 1; 
        string nombreidSupervisor  = "Walter"; 
        string apellidoidSupervisor  = "Ruiz"; 
        string emailidSupervisor  = "ruiz95gmail.com";
        int tipoidSupervisor  = 1;  
        int idSupervisorSupervisor  = 1;
        
        EmpleadoNomina *supervisor = new EmpleadoNomina(idSupervisor , nombreidSupervisor , apellidoidSupervisor , emailidSupervisor ,  tipoidSupervisor , idSupervisorSupervisor);
        
        // act:
        supervisor->AsignarEmpleado(empNomina);
        Empleado *actual = supervisor->ObtenerEmpleados().at(0);
        Empleado *esperado = empNomina;

        // assert:
        EXPECT_EQ(esperado, actual);  
    }

     TEST(Empleado_Tests, Test_Obtener_Id_Empleado){
        // arrange:
        int idEmpleadoNuevo = 8; 
        string nombreEmpleadoNuevo = "Ever"; 
        string apellidoEmpleadoNuevo = "Duarte"; 
        string emailEmpleadoNuevo = "duarte95gmail.com";
        int tipoEmpleadoNuevo = 1;  
        int idSupervisorEmpleadoNuevo = 1;

        EmpleadoNomina *empNomina = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    
        // act:
        int  actual = empNomina->ObtenerId();
        int esperado = idEmpleadoNuevo;

        // assert:
        EXPECT_EQ(esperado, actual);  
    }

    TEST(Empleado_Tests, Test_Obtener_Nombre_Empleado){
        // arrange:
        int idEmpleadoNuevo = 8; 
        string nombreEmpleadoNuevo = "Ever"; 
        string apellidoEmpleadoNuevo = "Duarte"; 
        string emailEmpleadoNuevo = "duarte95gmail.com";
        int tipoEmpleadoNuevo = 1;  
        int idSupervisorEmpleadoNuevo = 1;

        EmpleadoNomina *empNomina = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    
        // act:
        string  actual = empNomina->ObtenerNombre();
        string esperado = nombreEmpleadoNuevo;

        // assert:
        EXPECT_EQ(esperado, actual);  
    }

    TEST(Empleado_Tests, Test_Obtener_Apellido_Empleado){
        // arrange:
        int idEmpleadoNuevo = 8; 
        string nombreEmpleadoNuevo = "Ever"; 
        string apellidoEmpleadoNuevo = "Duarte"; 
        string emailEmpleadoNuevo = "duarte95gmail.com";
        int tipoEmpleadoNuevo = 1;  
        int idSupervisorEmpleadoNuevo = 1;

        EmpleadoNomina *empNomina = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    
        // act:
        string  actual = empNomina->ObtenerApellido();
        string esperado = apellidoEmpleadoNuevo;

        // assert:
        EXPECT_EQ(esperado, actual);  
    }

    TEST(Empleado_Tests, Test_Obtener_Correo_Empleado){
        // arrange:
        int idEmpleadoNuevo = 8; 
        string nombreEmpleadoNuevo = "Ever"; 
        string apellidoEmpleadoNuevo = "Duarte"; 
        string emailEmpleadoNuevo = "duarte95gmail.com";
        int tipoEmpleadoNuevo = 1;  
        int idSupervisorEmpleadoNuevo = 1;

        EmpleadoNomina *empNomina = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    
        // act:
        string  actual = empNomina->ObtenerCorreo();
        string esperado = emailEmpleadoNuevo;

        // assert:
        EXPECT_EQ(esperado, actual);  
    }

    TEST(Empleado_Tests, Test_Obtener_Tipo_Empleado){
        // arrange:
        int idEmpleadoNuevo = 8; 
        string nombreEmpleadoNuevo = "Ever"; 
        string apellidoEmpleadoNuevo = "Duarte"; 
        string emailEmpleadoNuevo = "duarte95gmail.com";
        int tipoEmpleadoNuevo = 1;  
        int idSupervisorEmpleadoNuevo = 1;

        EmpleadoNomina *empNomina = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    
        // act:
        int actual = empNomina->ObtenerTipoEmpleado();
        int esperado = tipoEmpleadoNuevo;

        // assert:
        EXPECT_EQ(esperado, actual);  
    }

    TEST(Empleado_Tests, Test_Obtener_Id__Supervisor_Empleado){
        // arrange:
        int idEmpleadoNuevo = 8; 
        string nombreEmpleadoNuevo = "Ever"; 
        string apellidoEmpleadoNuevo = "Duarte"; 
        string emailEmpleadoNuevo = "duarte95gmail.com";
        int tipoEmpleadoNuevo = 1;  
        int idSupervisorEmpleadoNuevo = 1;

        EmpleadoNomina *empNomina = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    
        // act:
        int actual = empNomina->ObtenerIdSupervisor();
        int esperado = idSupervisorEmpleadoNuevo;

        // assert:
        EXPECT_EQ(esperado, actual);  
    }

    TEST(Empleado_Tests, Test_Obtener_Supervisor_Empleado){
        // arrange:
        int idEmpleadoNuevo = 8; 
        string nombreEmpleadoNuevo = "Ever"; 
        string apellidoEmpleadoNuevo = "Duarte"; 
        string emailEmpleadoNuevo = "duarte95gmail.com";
        int tipoEmpleadoNuevo = 1;  
        int idSupervisorEmpleadoNuevo = 1;

        EmpleadoNomina *empNomina = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    
        int idSupervisor = 1; 
        string nombreidSupervisor  = "Walter"; 
        string apellidoidSupervisor  = "Ruiz"; 
        string emailidSupervisor  = "ruiz95gmail.com";
        int tipoidSupervisor  = 1;  
        int idSupervisorSupervisor  = 1;
        
        EmpleadoNomina *supervisor = new EmpleadoNomina(idSupervisor , nombreidSupervisor , apellidoidSupervisor , emailidSupervisor ,  tipoidSupervisor , idSupervisorSupervisor);
        
        // act:
        empNomina->AsignarSupervisor(supervisor);
        Empleado *actual = empNomina->ObtenerSupervisor();
        Empleado *esperado = supervisor;

        // assert:
        EXPECT_EQ(esperado, actual);  
    }

    TEST(Empleado_Tests, Test_Asignar_Supervisor_Empleado){
        // arrange:
        int idEmpleadoNuevo = 8; 
        string nombreEmpleadoNuevo = "Ever"; 
        string apellidoEmpleadoNuevo = "Duarte"; 
        string emailEmpleadoNuevo = "duarte95gmail.com";
        int tipoEmpleadoNuevo = 1;  
        int idSupervisorEmpleadoNuevo = 1;

        EmpleadoNomina *empNomina = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    
        int idSupervisor = 1; 
        string nombreidSupervisor  = "Walter"; 
        string apellidoidSupervisor  = "Ruiz"; 
        string emailidSupervisor  = "ruiz95gmail.com";
        int tipoidSupervisor  = 1;  
        int idSupervisorSupervisor  = 1;
        
        EmpleadoNomina *supervisor = new EmpleadoNomina(idSupervisor , nombreidSupervisor , apellidoidSupervisor , emailidSupervisor ,  tipoidSupervisor , idSupervisorSupervisor);
        
        // act:
        empNomina->AsignarSupervisor(supervisor);
        int actual = empNomina->ObtenerIdSupervisor();
        int esperado =  idSupervisorEmpleadoNuevo;

        // assert:
        EXPECT_EQ(esperado, actual);  
    }

    TEST(Empleado_Tests, Test_Asignar_Empleado){
        // arrange:
        int idEmpleadoNuevo = 8; 
        string nombreEmpleadoNuevo = "Ever"; 
        string apellidoEmpleadoNuevo = "Duarte"; 
        string emailEmpleadoNuevo = "duarte95gmail.com";
        int tipoEmpleadoNuevo = 1;  
        int idSupervisorEmpleadoNuevo = 1;

        EmpleadoNomina *empNomina = new EmpleadoNomina(idEmpleadoNuevo, nombreEmpleadoNuevo, apellidoEmpleadoNuevo, emailEmpleadoNuevo,  tipoEmpleadoNuevo, idSupervisorEmpleadoNuevo);
    
        int idSupervisor = 1; 
        string nombreidSupervisor  = "Walter"; 
        string apellidoidSupervisor  = "Ruiz"; 
        string emailidSupervisor  = "ruiz95gmail.com";
        int tipoidSupervisor  = 1;  
        int idSupervisorSupervisor  = 1;
        
        EmpleadoNomina *supervisor = new EmpleadoNomina(idSupervisor , nombreidSupervisor , apellidoidSupervisor , emailidSupervisor ,  tipoidSupervisor , idSupervisorSupervisor);
        
        // act:
        supervisor->AsignarEmpleado(empNomina);
        int actual = supervisor->ObtenerEmpleados().at(0)->ObtenerId();
        int esperado = idEmpleadoNuevo;

        // assert:
        EXPECT_EQ(esperado, actual);  
    }


}