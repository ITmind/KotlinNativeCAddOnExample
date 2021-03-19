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
    buildDir = file("../bin")
    targetMachines.add(machines.windows.x86_64)
    println("configure app")

}

tasks.withType(CppCompile::class){
    println("configure compile $name")
}

tasks.withType(LinkExecutable::class){
    println("configure link  $name")
}

tasks.withType(InstallExecutable::class){
    doLast{
        println("last install  $name")
    }
    println("configure install  $name")
}

tasks.withType(GradleBuild::class){
    println("configure link  $name")
}

val buildTask = tasks.findByName("build")
buildTask?.doLast {
    println("build  $name")
}
tasks.withType(GradleBuild::class){
    println("configure build  $name")
}