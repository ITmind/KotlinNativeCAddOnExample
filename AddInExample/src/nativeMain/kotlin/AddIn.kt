import kotlinx.cinterop.*
import kotlinx.cinterop.internal.CCall


class AddInClass{
    fun Test():String{
        return "Kotlin test ok"
    }
}

@CName("GetClassObject")
fun GetClassObject(pInterface: COpaquePointerVar): Int
{
    val adding = AddInClass()
    val stableRef = StableRef.create(adding)
    pInterface.value = stableRef.asCPointer()

    return 0
}