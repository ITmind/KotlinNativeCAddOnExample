plugins {
    id("cpp-application")
}

repositories {
    mavenCentral()
}

application {
    //buildTypes
    //publicHeaders.from(file("include"))
    privateHeaders {
        from("../bin")
    }
    //buildDir = file("../bin")
    targetMachines.add(machines.windows.x86_64)
}

tasks.register("MyTest"){
    dependsOn("build")
    //mustRunAfter(":mainC:build")
    doLast {
        println("myTest")
    }

    println("config myTest")
}

/*println("array of task:")
tasks.forEach {
    println("task ${it.name} is ${it.enabled}")
}*/

tasks.withType(CppCompile::class){
    //println("configure compile $name")
}

tasks.withType(LinkExecutable::class){
    //println("configure link  $name")
}

tasks.withType(InstallExecutable::class){
    doLast{
        //println("last install  $name")
    }
    //println("configure install  $name")
}

tasks.withType(GradleBuild::class){
    //println("configure link  $name")
}

tasks.getByName("build"){
    doLast {
        println("build2  $name")
    }
}