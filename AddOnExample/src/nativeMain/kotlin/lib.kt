import kotlinx.cinterop.CPointerVar
import kotlinx.cinterop.StableRef
import kotlinx.cinterop.value

@CName("GetClassObject")
fun GetClassObject(pInterface: CPointerVar<*>): Int
{
    val adding = AddOnClass()
    val stableRef = StableRef.create(adding)
    pInterface.value = stableRef.asCPointer()

    return 0
}
