/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-D20
 */
import java.util.*;
import org.mozilla.javascript.*;
import xdc.services.intern.xsr.*;
import xdc.services.spec.Session;

public class ti_drivers_rf
{
    static final String VERS = "@(#) xdc-D20\n";

    static final Proto.Elm $$T_Bool = Proto.Elm.newBool();
    static final Proto.Elm $$T_Num = Proto.Elm.newNum();
    static final Proto.Elm $$T_Str = Proto.Elm.newStr();
    static final Proto.Elm $$T_Obj = Proto.Elm.newObj();

    static final Proto.Fxn $$T_Met = new Proto.Fxn(null, null, 0, -1, false);
    static final Proto.Map $$T_Map = new Proto.Map($$T_Obj);
    static final Proto.Arr $$T_Vec = new Proto.Arr($$T_Obj);

    static final XScriptO $$DEFAULT = Value.DEFAULT;
    static final Object $$UNDEF = Undefined.instance;

    static final Proto.Obj $$Package = (Proto.Obj)Global.get("$$Package");
    static final Proto.Obj $$Module = (Proto.Obj)Global.get("$$Module");
    static final Proto.Obj $$Instance = (Proto.Obj)Global.get("$$Instance");
    static final Proto.Obj $$Params = (Proto.Obj)Global.get("$$Params");

    static final Object $$objFldGet = Global.get("$$objFldGet");
    static final Object $$objFldSet = Global.get("$$objFldSet");
    static final Object $$proxyGet = Global.get("$$proxyGet");
    static final Object $$proxySet = Global.get("$$proxySet");
    static final Object $$delegGet = Global.get("$$delegGet");
    static final Object $$delegSet = Global.get("$$delegSet");

    Scriptable xdcO;
    Session ses;
    Value.Obj om;

    boolean isROV;
    boolean isCFG;

    Proto.Obj pkgP;
    Value.Obj pkgV;

    ArrayList<Object> imports = new ArrayList<Object>();
    ArrayList<Object> loggables = new ArrayList<Object>();
    ArrayList<Object> mcfgs = new ArrayList<Object>();
    ArrayList<Object> icfgs = new ArrayList<Object>();
    ArrayList<String> inherits = new ArrayList<String>();
    ArrayList<Object> proxies = new ArrayList<Object>();
    ArrayList<Object> sizes = new ArrayList<Object>();
    ArrayList<Object> tdefs = new ArrayList<Object>();

    void $$IMPORTS()
    {
        Global.callFxn("loadPackage", xdcO, "ti.sysbios");
        Global.callFxn("loadPackage", xdcO, "ti.drivers");
        Global.callFxn("loadPackage", xdcO, "xdc");
        Global.callFxn("loadPackage", xdcO, "xdc.corevers");
    }

    void $$OBJECTS()
    {
        pkgP = (Proto.Obj)om.bind("ti.drivers.rf.Package", new Proto.Obj());
        pkgV = (Value.Obj)om.bind("ti.drivers.rf", new Value.Obj("ti.drivers.rf", pkgP));
    }

    void $$SINGLETONS()
    {
        pkgP.init("ti.drivers.rf.Package", (Proto.Obj)om.findStrict("xdc.IPackage.Module", "ti.drivers.rf"));
        Scriptable cap = (Scriptable)Global.callFxn("loadCapsule", xdcO, "ti/drivers/rf/package.xs");
        om.bind("xdc.IPackage$$capsule", cap);
        Object fxn;
                fxn = Global.get(cap, "init");
                if (fxn != null) pkgP.addFxn("init", (Proto.Fxn)om.findStrict("xdc.IPackage$$init", "ti.drivers.rf"), fxn);
                fxn = Global.get(cap, "close");
                if (fxn != null) pkgP.addFxn("close", (Proto.Fxn)om.findStrict("xdc.IPackage$$close", "ti.drivers.rf"), fxn);
                fxn = Global.get(cap, "validate");
                if (fxn != null) pkgP.addFxn("validate", (Proto.Fxn)om.findStrict("xdc.IPackage$$validate", "ti.drivers.rf"), fxn);
                fxn = Global.get(cap, "exit");
                if (fxn != null) pkgP.addFxn("exit", (Proto.Fxn)om.findStrict("xdc.IPackage$$exit", "ti.drivers.rf"), fxn);
                fxn = Global.get(cap, "getLibs");
                if (fxn != null) pkgP.addFxn("getLibs", (Proto.Fxn)om.findStrict("xdc.IPackage$$getLibs", "ti.drivers.rf"), fxn);
                fxn = Global.get(cap, "getSects");
                if (fxn != null) pkgP.addFxn("getSects", (Proto.Fxn)om.findStrict("xdc.IPackage$$getSects", "ti.drivers.rf"), fxn);
        pkgP.bind("$capsule", cap);
        pkgV.init2(pkgP, "ti.drivers.rf", Value.DEFAULT, false);
        pkgV.bind("$name", "ti.drivers.rf");
        pkgV.bind("$category", "Package");
        pkgV.bind("$$qn", "ti.drivers.rf.");
        pkgV.bind("$vers", Global.newArray());
        Value.Map atmap = (Value.Map)pkgV.getv("$attr");
        atmap.seal("length");
        imports.clear();
        imports.add(Global.newArray("ti.sysbios", Global.newArray()));
        imports.add(Global.newArray("ti.drivers", Global.newArray()));
        pkgV.bind("$imports", imports);
        StringBuilder sb = new StringBuilder();
        sb.append("var pkg = xdc.om['ti.drivers.rf'];\n");
        sb.append("if (pkg.$vers.length >= 3) {\n");
            sb.append("pkg.$vers.push(Packages.xdc.services.global.Vers.getDate(xdc.csd() + '/..'));\n");
        sb.append("}\n");
        sb.append("if ('ti.drivers.rf$$stat$base' in xdc.om) {\n");
            sb.append("pkg.packageBase = xdc.om['ti.drivers.rf$$stat$base'];\n");
            sb.append("pkg.packageRepository = xdc.om['ti.drivers.rf$$stat$root'];\n");
        sb.append("}\n");
        sb.append("pkg.build.libraries = [\n");
            sb.append("'lib/rf_multiMode_cc13x0.aem3',\n");
            sb.append("'lib/rf_multiMode_cc13x0.arm3',\n");
            sb.append("'lib/rf_multiMode_cc13x0.am3g',\n");
            sb.append("'lib/rf_singleMode_cc13x0.aem3',\n");
            sb.append("'lib/rf_singleMode_cc13x0.arm3',\n");
            sb.append("'lib/rf_singleMode_cc13x0.am3g',\n");
            sb.append("'lib/rf_multiMode_cc26x0.aem3',\n");
            sb.append("'lib/rf_multiMode_cc26x0.arm3',\n");
            sb.append("'lib/rf_multiMode_cc26x0.am3g',\n");
            sb.append("'lib/rf_singleMode_cc26x0.aem3',\n");
            sb.append("'lib/rf_singleMode_cc26x0.arm3',\n");
            sb.append("'lib/rf_singleMode_cc26x0.am3g',\n");
            sb.append("'lib/rf_multiMode_cc26x0r2.aem3',\n");
            sb.append("'lib/rf_multiMode_cc26x0r2.arm3',\n");
            sb.append("'lib/rf_multiMode_cc26x0r2.am3g',\n");
            sb.append("'lib/rf_singleMode_cc26x0r2.aem3',\n");
            sb.append("'lib/rf_singleMode_cc26x0r2.arm3',\n");
            sb.append("'lib/rf_singleMode_cc26x0r2.am3g',\n");
            sb.append("'lib/rf_multiMode_cc13x2.aem4f',\n");
            sb.append("'lib/rf_multiMode_cc13x2.am4fg',\n");
            sb.append("'lib/rf_multiMode_cc13x2.arm4f',\n");
            sb.append("'lib/rf_multiMode_cc26x2.aem4f',\n");
            sb.append("'lib/rf_multiMode_cc26x2.am4fg',\n");
            sb.append("'lib/rf_multiMode_cc26x2.arm4f',\n");
        sb.append("];\n");
        sb.append("pkg.build.libDesc = [\n");
            sb.append("['lib/rf_multiMode_cc13x0.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/rf_multiMode_cc13x0.arm3', {target: 'iar.targets.arm.M3', suffix: 'rm3'}],\n");
            sb.append("['lib/rf_multiMode_cc13x0.am3g', {target: 'gnu.targets.arm.M3', suffix: 'm3g'}],\n");
            sb.append("['lib/rf_singleMode_cc13x0.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/rf_singleMode_cc13x0.arm3', {target: 'iar.targets.arm.M3', suffix: 'rm3'}],\n");
            sb.append("['lib/rf_singleMode_cc13x0.am3g', {target: 'gnu.targets.arm.M3', suffix: 'm3g'}],\n");
            sb.append("['lib/rf_multiMode_cc26x0.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/rf_multiMode_cc26x0.arm3', {target: 'iar.targets.arm.M3', suffix: 'rm3'}],\n");
            sb.append("['lib/rf_multiMode_cc26x0.am3g', {target: 'gnu.targets.arm.M3', suffix: 'm3g'}],\n");
            sb.append("['lib/rf_singleMode_cc26x0.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/rf_singleMode_cc26x0.arm3', {target: 'iar.targets.arm.M3', suffix: 'rm3'}],\n");
            sb.append("['lib/rf_singleMode_cc26x0.am3g', {target: 'gnu.targets.arm.M3', suffix: 'm3g'}],\n");
            sb.append("['lib/rf_multiMode_cc26x0r2.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/rf_multiMode_cc26x0r2.arm3', {target: 'iar.targets.arm.M3', suffix: 'rm3'}],\n");
            sb.append("['lib/rf_multiMode_cc26x0r2.am3g', {target: 'gnu.targets.arm.M3', suffix: 'm3g'}],\n");
            sb.append("['lib/rf_singleMode_cc26x0r2.aem3', {target: 'ti.targets.arm.elf.M3', suffix: 'em3'}],\n");
            sb.append("['lib/rf_singleMode_cc26x0r2.arm3', {target: 'iar.targets.arm.M3', suffix: 'rm3'}],\n");
            sb.append("['lib/rf_singleMode_cc26x0r2.am3g', {target: 'gnu.targets.arm.M3', suffix: 'm3g'}],\n");
            sb.append("['lib/rf_multiMode_cc13x2.aem4f', {target: 'ti.targets.arm.elf.M4F', suffix: 'em4f'}],\n");
            sb.append("['lib/rf_multiMode_cc13x2.am4fg', {target: 'gnu.targets.arm.M4F', suffix: 'm4fg'}],\n");
            sb.append("['lib/rf_multiMode_cc13x2.arm4f', {target: 'iar.targets.arm.M4F', suffix: 'rm4f'}],\n");
            sb.append("['lib/rf_multiMode_cc26x2.aem4f', {target: 'ti.targets.arm.elf.M4F', suffix: 'em4f'}],\n");
            sb.append("['lib/rf_multiMode_cc26x2.am4fg', {target: 'gnu.targets.arm.M4F', suffix: 'm4fg'}],\n");
            sb.append("['lib/rf_multiMode_cc26x2.arm4f', {target: 'iar.targets.arm.M4F', suffix: 'rm4f'}],\n");
        sb.append("];\n");
        Global.eval(sb.toString());
    }

    void $$INITIALIZATION()
    {
        Value.Obj vo;

        if (isCFG) {
        }//isCFG
        Global.callFxn("init", pkgV);
        ((Value.Arr)om.findStrict("$packages", "ti.drivers.rf")).add(pkgV);
    }

    public void exec( Scriptable xdcO, Session ses )
    {
        this.xdcO = xdcO;
        this.ses = ses;
        om = (Value.Obj)xdcO.get("om", null);

        Object o = om.geto("$name");
        String s = o instanceof String ? (String)o : null;
        isCFG = s != null && s.equals("cfg");
        isROV = s != null && s.equals("rov");

        $$IMPORTS();
        $$OBJECTS();
        if (isROV) {
        }//isROV
        $$SINGLETONS();
        $$INITIALIZATION();
    }
}
