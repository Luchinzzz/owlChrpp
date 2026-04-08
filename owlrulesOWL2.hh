#ifndef OWL2__GUARD
#define OWL2__GUARD
/*
From line 9 to 668
queryEngineeringStudents<queryEngineeringStudents( E, F, G, H, K, ID )> { logicalName<logicalName( URIX, X )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, F, Y )>, owlClassAssertion<owlClassAssertion( X, E, true )> } --> ResultVec<ResultVec( makeVec( URIX, URIY ), ID )>
queryComplexStudents<queryComplexStudents( E, F, G, H, K, ID )> { logicalName<logicalName( URIS, S )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, G, Z )>, owlClassAssertion<owlClassAssertion( S, E, true )> } --> ResultVec<ResultVec( makeVec( URIS, URIC ), ID )>
querySubjectByObjectWithId<querySubjectByObjectWithId( URIP, get_next_id(  ) )> { logicalName<logicalName( URIP, P )> } --> querySubjectByObject<querySubjectByObject( P, ID )>
queryInstancesWithId<queryInstancesWithId( URIC, get_next_id(  ) )> { logicalName<logicalName( URIC, C )> } --> queryInstances<queryInstances( C, ID )>
queryDataAssertionWithId<queryDataAssertionWithId( URIP, get_next_id(  ) )> { logicalName<logicalName( URIP, P )> } --> queryDataAssertion<queryDataAssertion( P, ID )>
queryObjAssertionSubjectWithId<queryObjAssertionSubjectWithId( URIP, URIO, get_next_id(  ) )> { logicalName<logicalName( URIP, P )> } --> queryObjAssertionSubject<queryObjAssertionSubject( P, O, ID )>
owlObjectPropertyChain<owlObjectPropertyChain( PC, P, 0, N )> { constructPropertyChain<constructPropertyChain( PC, I, X, Y, N )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )> } --> constructPropertyChain<constructPropertyChain( PC, 0, X, Y, N )>
constructPropertyChain<constructPropertyChain( PC, I, X, Y, N )> { owlObjectPropertyChain<owlObjectPropertyChain( PC, P, J, N )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( Y, P, Z )>, constructPropertyChain<constructPropertyChain( PC, I, X, Y, N )> } --> owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, PC, Y )>, constructPropertyChain<constructPropertyChain( PC, ( I + 1 ), X, Z, N )>
realisation<realisation(  )> { logicalName<logicalName( URIC, C )>, owlClassAssertion<owlClassAssertion( X, C, true )> } --> resultRealisation<resultRealisation( URIX, URIC )>
classification<classification(  )> { logicalName<logicalName( URIX, X )>, owlSubclassOf<owlSubclassOf( X, Y )>, classification<classification(  )> } --> resultClassification<resultClassification( URIX, URIY )>
owlOneOfLoop<owlOneOfLoop( C, IT, ITEND )> { owlOneOfLoop<owlOneOfLoop( C, IT, ITEND )> } --> owlOneOfLoop<owlOneOfLoop( C, ( std :: next( ( *IT ) ) ), ITEND )>, owlClassAssertion<owlClassAssertion( ( *( *IT ) ), C, true )>
owlDataMaxCardinality<owlDataMaxCardinality( C, P, N )> { owlDataPropertyAssertion<owlDataPropertyAssertion( U, P, _ )>, owlClassAssertion<owlClassAssertion( U, C, true )>, owlDataMaxCardinality<owlDataMaxCardinality( C, P, N )> } -->
owlHasKey<owlHasKey( C, P, I, N )> { owlDataPropertyAssertion<owlDataPropertyAssertion( X, P, V )>, owlHasKeyCheck<owlHasKeyCheck( C, X, Y, I, N )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, V )>, owlClassAssertion<owlClassAssertion( X, C, true )>, owlHasKey<owlHasKey( C, P, I, N )> } --> owlHasKeyCheck<owlHasKeyCheck( C, X, Y, 0, N )>
owlUnionOfLoop<owlUnionOfLoop( C, ( ( *S ) . begin(  ) ), ( ( *S ) . end(  ) ) )> --> owlUnionOfLoop<owlUnionOfLoop( C, ( std :: next( ( *IT ) ) ), ITEND )>, owlUnionClass<owlUnionClass( C, ( *( *IT ) ) )>
owlObjectMaxCardinality<owlObjectMaxCardinality( C, P, N )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( U, P, _ )>, owlClassAssertion<owlClassAssertion( U, C, true )>, owlObjectMaxCardinality<owlObjectMaxCardinality( C, P, N )> } --> owlSameIndividual<owlSameIndividual( Y1, Y2 )>
resultRealisation<resultRealisation( X, Y )> { resultRealisation<resultRealisation( X, Y )> } --> built-in<stockerRealisation( URIX, URIY )>
queryEquivalentClassReal<queryEquivalentClassReal( I, X )> { queryEquivalentClassReal<queryEquivalentClassReal( I, X )> } -->
queryClassificationReal<queryClassificationReal( X )> { queryClassificationReal<queryClassificationReal( X )> } -->
queryEquivalentClass<queryEquivalentClass( X )> { logicalName<logicalName( URIY, Y )>, owlEquivalentClass<owlEquivalentClass( X, Y )>, queryEquivalentClass<queryEquivalentClass( X )> } --> res<res( URIY )>
queryObjAssertionClass<queryObjAssertionClass( P, C )> { queryObjAssertionClass<queryObjAssertionClass( P, C )> } -->
queryObjAssertionSubject<queryObjAssertionSubject( P, O, ID )> { logicalName<logicalName( URIX, X )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, O )>, queryObjAssertionSubject<queryObjAssertionSubject( P, O, ID )> } --> ResultVec<ResultVec( makeVec( URIX, emptyString ), ID )>
queryDataAssertionUri<queryDataAssertionUri( URIP )> { queryDataAssertionUri<queryDataAssertionUri( URIP )> } --> queryDataAssertionWithId<queryDataAssertionWithId( URIP, get_next_id(  ) )>
querySubjectByObject<querySubjectByObject( P, ID )> { logicalName<logicalName( URIX, X )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )>, querySubjectByObject<querySubjectByObject( P, ID )> } --> ResultVec<ResultVec( makeVec( URIX, URIY ), ID )>
queryObjAssertion<queryObjAssertion( P, ID )> { logicalName<logicalName( URIX, X )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )>, queryObjAssertion<queryObjAssertion( P, ID )> } --> ResultVec<ResultVec( makeVec( URIX, URIY ), ID )>
queryObjAssertionUri<queryObjAssertionUri( URIP )> { queryObjAssertionUri<queryObjAssertionUri( URIP )> } --> queryObjAssertionWithId<queryObjAssertionWithId( URIP, get_next_id(  ) )>
queryInstances<queryInstances( C, ID )> { logicalName<logicalName( URIX, X )>, owlClassAssertion<owlClassAssertion( X, C, true )>, queryInstances<queryInstances( C, ID )> } --> ResultVec<ResultVec( makeVec( URIX, emptyString ), ID )>
querySuperClassOfReal<querySuperClassOfReal( I, C )> { querySuperClassOfReal<querySuperClassOfReal( I, C )> } -->
queryInstancesURI<queryInstancesURI( URIC )> { queryInstancesURI<queryInstancesURI( URIC )> } --> queryInstancesWithId<queryInstancesWithId( URIC, get_next_id(  ) )>
owlIrreflexiveObjectProperty<owlIrreflexiveObjectProperty( P )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, X )>, owlIrreflexiveObjectProperty<owlIrreflexiveObjectProperty( P )> } -->
owlSubObjectPropertyOf<owlSubObjectPropertyOf( A, B )> { owlSubclassOf<owlSubclassOf( Y1, Y2 )>, owlObjectSomeValuesFrom<owlObjectSomeValuesFrom( SV, P2, Y )>, owlHasValueObject<owlHasValueObject( C, P1, A )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P2, Y )>, owlClassAssertion<owlClassAssertion( A, Y, true )>, owlObjectPropertyRange<owlObjectPropertyRange( P2, C )>, owlObjectPropertyDomain<owlObjectPropertyDomain( P2, C )>, owlSubObjectPropertyOf<owlSubObjectPropertyOf( A, B )> } --> owlSubclassOf<owlSubclassOf( C, SV )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P1, Y )>, owlObjectPropertyRange<owlObjectPropertyRange( P1, C )>, owlEquivalentObjectProperty<owlEquivalentObjectProperty( A, B )>, owlObjectPropertyDomain<owlObjectPropertyDomain( P1, C )>, owlSubObjectPropertyOf<owlSubObjectPropertyOf( A, C )>
logicalName<logicalName( URI, X )> { queryComplexStudents<queryComplexStudents( E, F, G, H, K, ID )>, queryEngineeringStudents<queryEngineeringStudents( E, F, G, H, K, ID )>, querySubjectByObject<querySubjectByObject( P, ID )>, queryComplexStudentsWithId<queryComplexStudentsWithId( URIE, URIF, URIG, URIH, URIK, ID )>, querySubClassOf<querySubClassOf( X )>, querySuperClassOfUri<querySuperClassOfUri( URIC )>, queryInstances<queryInstances( C, ID )>, querySubClassOfUri<querySubClassOfUri( URIC )>, querySuperClassOf<querySuperClassOf( X )>, logicalName<logicalName( URI, X )>, owlEquivalentClass<owlEquivalentClass( X, Y )>, queryObjAssertion<queryObjAssertion( P, ID )>, querySuperClassOfClassUri<querySuperClassOfClassUri( URIX, URIY )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( U, P, W )>, queryEngineeringStudentsWithId<queryEngineeringStudentsWithId( URIE, URIF, URIG, URIH, URIK, ID )>, owlClassAssertion<owlClassAssertion( W, Y, true )>, owlClass<owlClass( C )>, querySubClassOfClassUri<querySubClassOfClassUri( URIX, URIY )>, owlSubclassOf<owlSubclassOf( X, Y )>, queryClassificationUri<queryClassificationUri( URIX )>, queryEquivalentClass<queryEquivalentClass( X )>, queryClassification<queryClassification( X )>, queryInstanceURI<queryInstanceURI( URIX, URIC )>, queryObjAssertionSubjectWithId<queryObjAssertionSubjectWithId( URIP, URIO, ID )>, resultClassification<resultClassification( URIX, URIY )>, classification<classification(  )>, queryDataAssertion<queryDataAssertion( P, ID )>, owlDataPropertyAssertion<owlDataPropertyAssertion( X, P, Y )>, querySubjectByObjectWithId<querySubjectByObjectWithId( URIP, ID )>, queryDataAssertionWithId<queryDataAssertionWithId( URIP, ID )>, queryInstancesWithId<queryInstancesWithId( URIC, ID )>, realisation<realisation(  )>, queryObjAssertionWithId<queryObjAssertionWithId( URIP, ID )>, queryObjAssertionSubject<queryObjAssertionSubject( P, O, ID )> } --> queryComplexStudents<queryComplexStudents( E, F, G, H, K, ID )>, queryEngineeringStudents<queryEngineeringStudents( E, F, G, H, K, ID )>, queryObjAssertionSubject<queryObjAssertionSubject( P, O, ID )>, queryDataAssertion<queryDataAssertion( P, ID )>, querySubjectByObject<querySubjectByObject( P, ID )>, owlSubclassOf<owlSubclassOf( C, OwlThingVar )>, resultRealisation<resultRealisation( URIX, URIC )>, querySuperClassOf<querySuperClassOf( X )>, res<res( URIC )>, queryClassification<queryClassification( X )>, queryObjAssertion<queryObjAssertion( P, ID )>, queryEquivalentClass<queryEquivalentClass( X )>, queryInstances<queryInstances( C, ID )>, querySuperClassOfClass<querySuperClassOfClass( X, Y )>, querySubClassOf<querySubClassOf( X )>, querySubClassOfClass<querySubClassOfClass( X, Y )>, queryInstance<queryInstance( X, C )>, resultClassification<resultClassification( URIX, URIY )>, ResultVec<ResultVec( makeVec( URIX, URIY ), ID )>
owlDataProperty<owlDataProperty( P )> { owlDataProperty<owlDataProperty( P )> } --> owlSubDataPropertyOf<owlSubDataPropertyOf( P, P )>, owlEquivalentDataProperty<owlEquivalentDataProperty( P, P )>
owlDataValue<owlDataValue( V, S, T )> { owlDataPropertyAssertion<owlDataPropertyAssertion( U, P, W )>, owlDataValue<owlDataValue( V, S, T )> } -->
ResultVec<ResultVec( S, ID )> { ResultVec<ResultVec( S, ID )> } --> built-in<afficherResultatSet( S, ID )>
owlDisjointDataProperty<owlDisjointDataProperty( A, B )> { owlDataPropertyAssertion<owlDataPropertyAssertion( X, A, Y )>, owlDisjointDataProperty<owlDisjointDataProperty( A, B )> } -->
owlOneOf<owlOneOf( C, S )> { owlOneOf<owlOneOf( C, S )> } --> owlOneOfLoop<owlOneOfLoop( C, ( ( *S ) . begin(  ) ), ( ( *S ) . end(  ) ) )>
owlInverseObjectProperty<owlInverseObjectProperty( P1, P2 )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P1, Y )>, owlInverseObjectProperty<owlInverseObjectProperty( P1, P2 )> } --> owlInverseObjectProperty<owlInverseObjectProperty( P2, P1 )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( Y, P2, X )>
owlComplementOf<owlComplementOf( A, NOTA )> { owlNamedIndividual<owlNamedIndividual( X )>, owlClassAssertion<owlClassAssertion( X, A, true )>, owlComplementOf<owlComplementOf( A, NOTA )> } --> owlClassAssertion<owlClassAssertion( X, NOTA, false )>
queryInstanceURI<queryInstanceURI( URIX, URIC )> { logicalName<logicalName( URIC, C )>, queryInstanceURI<queryInstanceURI( URIX, URIC )> } --> queryInstance<queryInstance( X, C )>
queryClassificationTempUri<queryClassificationTempUri( URI )> { queryClassificationTempUri<queryClassificationTempUri( URI )> } -->
owlCandidatsIntersection<owlCandidatsIntersection( X, C, I )> { owlIntersectionOfLoop<owlIntersectionOfLoop( C, ITEND, ITEND, I )>, owlClassAssertion<owlClassAssertion( X, V, true )>, owlIntersectionClass<owlIntersectionClass( C, V, I )>, owlCandidatsIntersection<owlCandidatsIntersection( X, C, I )> } --> owlClassAssertion<owlClassAssertion( X, C, true )>, owlCandidatsIntersection<owlCandidatsIntersection( X, C, ( I + 1 ) )>
owlNegativeObjectAssertion<owlNegativeObjectAssertion( X, P, Y )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )>, owlNegativeObjectAssertion<owlNegativeObjectAssertion( X, P, Y )> } -->
owlObjectProperty<owlObjectProperty( P )> { owlClassAssertion<owlClassAssertion( U, C, true )>, owlHasValueObject<owlHasValueObject( C, P, Y )>, owlObjectProperty<owlObjectProperty( P )> } --> owlObjectPropertyAssertion<owlObjectPropertyAssertion( U, P, Y )>, owlEquivalentObjectProperty<owlEquivalentObjectProperty( P, P )>, owlSubObjectPropertyOf<owlSubObjectPropertyOf( P, P )>
owlHasValueObject<owlHasValueObject( C, P, Y )> { owlSubObjectPropertyOf<owlSubObjectPropertyOf( P1, P2 )>, owlSubclassOf<owlSubclassOf( Y1, Y2 )>, owlObjectSomeValuesFrom<owlObjectSomeValuesFrom( SV, P, Y )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( U, P, Y )>, owlClassAssertion<owlClassAssertion( U, C, true )>, owlObjectProperty<owlObjectProperty( P )>, owlHasValueObject<owlHasValueObject( C, P, Y )> } --> owlSubclassOf<owlSubclassOf( C, SV )>, owlClassAssertion<owlClassAssertion( U, C, true )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( U, P, Y )>
res<res( X )> { res<res( X )> } --> built-in<afficher( URIC )>
owlDataSomeValuesFrom<owlDataSomeValuesFrom( C, P, DR )> { owlClassAssertion<owlClassAssertion( U, C, true )>, owlDataPropertyAssertion<owlDataPropertyAssertion( U, P, V )>, owlDataSomeValuesFrom<owlDataSomeValuesFrom( C, P, DR )> } --> logicalName<logicalName( emptyString, V )>, owlDataPropertyAssertion<owlDataPropertyAssertion( U, P, createValue( emptyString, DR ) )>, owlClassAssertion<owlClassAssertion( U, C, true )>
owlDisjointClass<owlDisjointClass( A, B )> { owlClassAssertion<owlClassAssertion( X, A, true )>, owlDisjointClass<owlDisjointClass( A, B )> } -->
owlObjectSomeValuesFrom<owlObjectSomeValuesFrom( C, P, Y )> { owlSubObjectPropertyOf<owlSubObjectPropertyOf( P1, P2 )>, owlSubclassOf<owlSubclassOf( Y1, Y2 )>, owlHasValueObject<owlHasValueObject( C, P, A )>, owlClassAssertion<owlClassAssertion( V, Y, true )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( U, P, V )>, owlObjectSomeValuesFrom<owlObjectSomeValuesFrom( C, P, Y )> } --> owlSubclassOf<owlSubclassOf( C, SV )>, logicalName<logicalName( emptyString, V )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( U, P, V )>, owlClassAssertion<owlClassAssertion( U, C, true )>, owlEquivalentClass<owlEquivalentClass( C1, C2 )>
queryEngineeringStudentsUri<queryEngineeringStudentsUri( URIE, URIF, URIG, URIH, URIK )> --> queryEngineeringStudentsWithId<queryEngineeringStudentsWithId( URIE, URIF, URIG, URIH, URIK, get_next_id(  ) )>
owlNamedIndividual<owlNamedIndividual( C )> { owlComplementOf<owlComplementOf( A, NOTA )>, owlNamedIndividual<owlNamedIndividual( C )> } --> owlClassAssertion<owlClassAssertion( X, NOTA, false )>
owlObjectPropertyRange<owlObjectPropertyRange( P, C )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )>, owlSubObjectPropertyOf<owlSubObjectPropertyOf( P1, P2 )>, owlSubclassOf<owlSubclassOf( C1, C2 )>, owlObjectPropertyRange<owlObjectPropertyRange( P, C )> } --> owlClassAssertion<owlClassAssertion( Y, DP, true )>, owlObjectPropertyRange<owlObjectPropertyRange( P, C2 )>
owlSameIndividual<owlSameIndividual( X, Y )> { owlDifferentIndividual<owlDifferentIndividual( X, Y )>, owlClassAssertion<owlClassAssertion( X, C, B )>, owlDataPropertyAssertion<owlDataPropertyAssertion( X, P, O )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, O )>, owlSameIndividual<owlSameIndividual( X, Y )> } --> owlClassAssertion<owlClassAssertion( Y, C, B )>, owlDataPropertyAssertion<owlDataPropertyAssertion( Y, P, O )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( Y, P, O )>, owlSameIndividual<owlSameIndividual( Y, X )>
owlPrefix<owlPrefix( X, Y )> { owlPrefix<owlPrefix( X, Y )> } -->
owlEquivalentClass<owlEquivalentClass( A, B )> { resultClassification<resultClassification( URIX, URIY )>, logicalName<logicalName( URIY, Y )>, queryEquivalentClass<queryEquivalentClass( X )>, owlClassAssertion<owlClassAssertion( X, A, true )>, owlEquivalentClass<owlEquivalentClass( A, B )> } --> res<res( URIY )>, owlSubclassOf<owlSubclassOf( A, B )>, owlClassAssertion<owlClassAssertion( X, B, true )>
owlHasKeyCheck<owlHasKeyCheck( C, X, Y, I, N )> { owlDataPropertyAssertion<owlDataPropertyAssertion( X, P, V )>, owlHasKey<owlHasKey( C, P, I, N )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, V )>, owlHasKeyCheck<owlHasKeyCheck( C, X, Y, I, N )> } --> owlSameIndividual<owlSameIndividual( X, Y )>, owlHasKeyCheck<owlHasKeyCheck( C, X, Y, ( I + 1 ), N )>
queryDataAssertion<queryDataAssertion( P, ID )> { logicalName<logicalName( URIX, X )>, owlDataPropertyAssertion<owlDataPropertyAssertion( X, P, Y )>, queryDataAssertion<queryDataAssertion( P, ID )> } --> ResultVec<ResultVec( makeVec( URIX, valueToString( Y ) ), ID )>
owlNegativeDataAssertion<owlNegativeDataAssertion( X, P, Y )> { owlDataPropertyAssertion<owlDataPropertyAssertion( X, P, Y )>, owlNegativeDataAssertion<owlNegativeDataAssertion( X, P, Y )> } -->
owlClass<owlClass( C )> { logicalName<logicalName( URIC, C )>, owlClass<owlClass( C )> } --> owlSubclassOf<owlSubclassOf( C, OwlThingVar )>, owlEquivalentClass<owlEquivalentClass( C, C )>
owlObjectPropertyDomain<owlObjectPropertyDomain( P, C )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )>, owlSubclassOf<owlSubclassOf( C1, C2 )>, owlSubObjectPropertyOf<owlSubObjectPropertyOf( P1, P2 )>, owlObjectPropertyDomain<owlObjectPropertyDomain( P, C )> } --> owlClassAssertion<owlClassAssertion( X, DP, true )>, owlObjectPropertyDomain<owlObjectPropertyDomain( P, C2 )>
querySubClassOfClassUri<querySubClassOfClassUri( URIX, URIY )> { logicalName<logicalName( URIX, X )>, querySubClassOfClassUri<querySubClassOfClassUri( URIX, URIY )> } --> querySubClassOfClass<querySubClassOfClass( X, Y )>
owlSubDataPropertyOf<owlSubDataPropertyOf( A, B )> { owlDataPropertyAssertion<owlDataPropertyAssertion( X, P2, Y )>, owlDataPropertyRange<owlDataPropertyRange( P2, C )>, owlDataPropertyDomain<owlDataPropertyDomain( P2, C )>, owlSubDataPropertyOf<owlSubDataPropertyOf( A, B )> } --> owlDataPropertyAssertion<owlDataPropertyAssertion( X, P1, Y )>, owlDataPropertyRange<owlDataPropertyRange( P1, C )>, owlDataPropertyDomain<owlDataPropertyDomain( P1, C )>, owlEquivalentDataProperty<owlEquivalentDataProperty( A, B )>, owlSubDataPropertyOf<owlSubDataPropertyOf( A, C )>
queryObjAssertionWithId<queryObjAssertionWithId( URIP, get_next_id(  ) )> { logicalName<logicalName( URIP, P )> } --> queryObjAssertion<queryObjAssertion( P, ID )>
resultClassification<resultClassification( X, Y )> { logicalName<logicalName( URIX, X )>, owlEquivalentClass<owlEquivalentClass( X, Y )>, resultClassification<resultClassification( X, Y )> } --> built-in<stockerClassification( URIX, URIY )>
owlDisjointObjectProperty<owlDisjointObjectProperty( A, B )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, A, Y )>, owlDisjointObjectProperty<owlDisjointObjectProperty( A, B )> } -->
owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )> { querySubjectByObject<querySubjectByObject( P, ID )>, queryObjAssertion<queryObjAssertion( P, ID )>, owlHasKeyCheck<owlHasKeyCheck( C, X, Y, I, N )>, queryComplexStudents<queryComplexStudents( E, F, G, H, K, ID )>, owlHasKey<owlHasKey( C, P, I, N )>, owlObjectPropertyChain<owlObjectPropertyChain( PC, P, 0, N )>, owlObjectMaxCardinality<owlObjectMaxCardinality( C, P, 0 )>, owlClassAssertion<owlClassAssertion( V, Y, true )>, owlObjectSomeValuesFrom<owlObjectSomeValuesFrom( C, P, Y )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )>, owlSameIndividual<owlSameIndividual( X, Y )>, queryObjAssertionSubject<queryObjAssertionSubject( P, O, ID )>, owlNegativeObjectAssertion<owlNegativeObjectAssertion( X, P, Y )>, owlReflexiveObjectProperty<owlReflexiveObjectProperty( P )>, owlFunctionalObjectProperty<owlFunctionalObjectProperty( P )>, logicalName<logicalName( URI, W )>, owlIrreflexiveObjectProperty<owlIrreflexiveObjectProperty( P )>, constructPropertyChain<constructPropertyChain( PC, I, X, Y, N )>, owlInverseObjectProperty<owlInverseObjectProperty( P1, P2 )>, queryEngineeringStudents<queryEngineeringStudents( E, F, G, H, K, ID )>, owlDisjointObjectProperty<owlDisjointObjectProperty( A, B )>, owlAsymmetricObjectProperty<owlAsymmetricObjectProperty( P )>, owlInverseFunctionalObjectProperty<owlInverseFunctionalObjectProperty( P )>, owlSubObjectPropertyOf<owlSubObjectPropertyOf( P2, P1 )>, owlHasValueObject<owlHasValueObject( C, P, Y )>, owlObjectPropertyDomain<owlObjectPropertyDomain( P, DP )>, owlObjectPropertyRange<owlObjectPropertyRange( P, DP )>, owlSymmetricObjectProperty<owlSymmetricObjectProperty( P )> } --> owlHasKeyCheck<owlHasKeyCheck( C, X, Y, ( I + 1 ), N )>, ResultVec<ResultVec( makeVec( URIX, URIY ), ID )>, owlNegativeObjectAssertion<owlNegativeObjectAssertion( Y, P, X )>, owlClassAssertion<owlClassAssertion( X, DP, true )>, constructPropertyChain<constructPropertyChain( PC, 0, X, Y, N )>, owlSameIndividual<owlSameIndividual( Y, Z )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P1, Y )>
owlSymmetricObjectProperty<owlSymmetricObjectProperty( P )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )>, owlSymmetricObjectProperty<owlSymmetricObjectProperty( P )> } --> owlObjectPropertyAssertion<owlObjectPropertyAssertion( Y, P, X )>
queryClassificationTemp<queryClassificationTemp( X )> { queryClassificationTemp<queryClassificationTemp( X )> } -->
querySuperClassOfClassUri<querySuperClassOfClassUri( URIX, URIY )> { logicalName<logicalName( URIX, X )>, querySuperClassOfClassUri<querySuperClassOfClassUri( URIX, URIY )> } --> querySuperClassOfClass<querySuperClassOfClass( X, Y )>
owlEquivalentDataProperty<owlEquivalentDataProperty( A, B )> { owlEquivalentDataProperty<owlEquivalentDataProperty( A, B )> } --> owlSubDataPropertyOf<owlSubDataPropertyOf( A, B )>
owlEquivalentObjectProperty<owlEquivalentObjectProperty( A, B )> { owlEquivalentObjectProperty<owlEquivalentObjectProperty( A, B )> } --> owlSubObjectPropertyOf<owlSubObjectPropertyOf( A, B )>
owlDifferentIndividual<owlDifferentIndividual( X, Y )> { owlSameIndividual<owlSameIndividual( X, Y )>, owlDifferentIndividual<owlDifferentIndividual( X, Y )> } -->
queryFullUri<queryFullUri( X )> { queryFullUri<queryFullUri( X )> } -->
querySubjectByObjectUri<querySubjectByObjectUri( URIP )> { querySubjectByObjectUri<querySubjectByObjectUri( URIP )> } --> querySubjectByObjectWithId<querySubjectByObjectWithId( URIP, get_next_id(  ) )>
owlClassAssertion<owlClassAssertion( X, A, B )> { queryInstances<queryInstances( C, ID )>, realisation<realisation(  )>, queryInstance<queryInstance( X, C )>, queryClassification<queryClassification( X )>, owlSubObjectPropertyOf<owlSubObjectPropertyOf( P1, P2 )>, owlHasValueObject<owlHasValueObject( C, P, Y )>, owlDataMaxCardinality<owlDataMaxCardinality( C, P, 0 )>, owlObjectMaxCardinality<owlObjectMaxCardinality( C, P, 0 )>, owlDataPropertyAssertion<owlDataPropertyAssertion( U, P, _ )>, owlDisjointClass<owlDisjointClass( A, B )>, queryEngineeringStudents<queryEngineeringStudents( E, F, G, H, K, ID )>, owlCandidatsIntersection<owlCandidatsIntersection( X, C, I )>, owlComplementOf<owlComplementOf( A, NOTA )>, owlSameIndividual<owlSameIndividual( X, Y )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( U, P, V )>, owlClassAssertion<owlClassAssertion( X, A, B )>, owlDataSomeValuesFrom<owlDataSomeValuesFrom( C, P, DR )>, owlSubclassOf<owlSubclassOf( A, B )>, logicalName<logicalName( URI, W )>, queryComplexStudents<queryComplexStudents( E, F, G, H, K, ID )>, owlHasKey<owlHasKey( C, P, 0, N )>, owlEquivalentClass<owlEquivalentClass( A, B )>, owlIntersectionClass<owlIntersectionClass( C, V, 0 )>, owlObjectProperty<owlObjectProperty( P )>, owlUnionClass<owlUnionClass( C, V )>, owlObjectSomeValuesFrom<owlObjectSomeValuesFrom( C, P, Y )> } --> ResultVec<ResultVec( makeVec( URIX, emptyString ), ID )>, resultRealisation<resultRealisation( URIX, URIC )>, built-in<afficher( "true" )>, owlClassAssertion<owlClassAssertion( X, B, true )>, owlNamedIndividual<owlNamedIndividual( X )>, owlCandidatsIntersection<owlCandidatsIntersection( X, C, 0 )>, owlClass<owlClass( C )>, owlHasKeyCheck<owlHasKeyCheck( C, X, Y, 0, N )>, owlObjectPropertyAssertion<owlObjectPropertyAssertion( U, P, V )>, owlSameIndividual<owlSameIndividual( Y1, Y2 )>, querySuperClassOf<querySuperClassOf( C )>, logicalName<logicalName( emptyString, V )>, owlSubclassOf<owlSubclassOf( C, SV )>, owlDataPropertyAssertion<owlDataPropertyAssertion( U, P, createValue( emptyString, DR ) )>, res<res( URIC )>, queryEquivalentClass<queryEquivalentClass( C )>
queryObjAssertionClassUri<queryObjAssertionClassUri( URIP, URIC )> { queryObjAssertionClassUri<queryObjAssertionClassUri( URIP, URIC )> } -->
owlDataPropertyDomain<owlDataPropertyDomain( P, C )> { owlDataPropertyAssertion<owlDataPropertyAssertion( X, P, _ )>, owlSubDataPropertyOf<owlSubDataPropertyOf( P1, P2 )>, owlDataPropertyDomain<owlDataPropertyDomain( P, C )> } --> owlClassAssertion<owlClassAssertion( X, DP, true )>, owlDataPropertyDomain<owlDataPropertyDomain( P1, C )>
owlTransitiveObjectProperty<owlTransitiveObjectProperty( P )> { owlTransitiveObjectProperty<owlTransitiveObjectProperty( P )> } -->
queryComplexStudentsWithId<queryComplexStudentsWithId( URIE, URIF, URIG, URIH, URIK, get_next_id(  ) )> { logicalName<logicalName( URIE, E )> } --> queryComplexStudents<queryComplexStudents( E, F, G, H, K, ID )>
queryInstance<queryInstance( X, C )> { owlClassAssertion<owlClassAssertion( X, C, true )>, queryInstance<queryInstance( X, C )> } --> built-in<afficher( "true" )>
owlDataPropertyAssertion<owlDataPropertyAssertion( X, P, Y )> { logicalName<logicalName( URIX, X )>, queryDataAssertion<queryDataAssertion( P, ID )>, owlDataPropertyAssertion<owlDataPropertyAssertion( X, P, Y )>, owlDisjointDataProperty<owlDisjointDataProperty( A, B )>, owlSameIndividual<owlSameIndividual( X, Y )>, owlDataValue<owlDataValue( W, ValW, TypeW )>, owlDataPropertyRange<owlDataPropertyRange( P, DR )>, owlSubDataPropertyOf<owlSubDataPropertyOf( P2, P1 )>, owlHasKeyCheck<owlHasKeyCheck( C, X, Y, I, N )>, owlFunctionalDataProperty<owlFunctionalDataProperty( P )>, owlDataMaxCardinality<owlDataMaxCardinality( C, P, 0 )>, owlDataSomeValuesFrom<owlDataSomeValuesFrom( C, P, DR )>, owlDataPropertyDomain<owlDataPropertyDomain( P, DP )>, owlClassAssertion<owlClassAssertion( U, C, true )>, owlNegativeDataAssertion<owlNegativeDataAssertion( X, P, Y )>, owlHasKey<owlHasKey( C, P, I, N )> } --> owlHasKeyCheck<owlHasKeyCheck( C, X, Y, ( I + 1 ), N )>, owlDataValue<owlDataValue( Y, ( ( *Y ) . val ), ( ( *Y ) . typeVal ) )>, ResultVec<ResultVec( makeVec( URIX, valueToString( Y ) ), ID )>, owlDataPropertyAssertion<owlDataPropertyAssertion( X, P1, Y )>, owlClassAssertion<owlClassAssertion( X, DP, true )>
querySubClassOfClass<querySubClassOfClass( X, Y )> { owlSubclassOf<owlSubclassOf( X, Y )>, querySubClassOfClass<querySubClassOfClass( X, Y )> } --> built-in<afficher( "true" )>
queryComplexStudentsUri<queryComplexStudentsUri( URIE, URIF, URIG, URIH, URIK )> --> queryComplexStudentsWithId<queryComplexStudentsWithId( URIE, URIF, URIG, URIH, URIK, get_next_id(  ) )>
owlFunctionalObjectProperty<owlFunctionalObjectProperty( P )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )>, owlFunctionalObjectProperty<owlFunctionalObjectProperty( P )> } --> owlSameIndividual<owlSameIndividual( Y, Z )>
queryClassification<queryClassification( X )> { logicalName<logicalName( URIC, C )>, owlClassAssertion<owlClassAssertion( X, C, true )>, queryClassification<queryClassification( X )> } --> queryEquivalentClass<queryEquivalentClass( C )>, querySuperClassOf<querySuperClassOf( C )>, res<res( URIC )>
owlIntersectionOf<owlIntersectionOf( C, S )> { owlIntersectionOf<owlIntersectionOf( C, S )> } --> owlIntersectionOfLoop<owlIntersectionOfLoop( C, ( ( *S ) . begin(  ) ), ( ( *S ) . end(  ) ), 0 )>
owlFunctionalDataProperty<owlFunctionalDataProperty( P )> { owlDataPropertyAssertion<owlDataPropertyAssertion( X, P, Y )>, owlFunctionalDataProperty<owlFunctionalDataProperty( P )> } -->
owlUnionClass<owlUnionClass( C, V )> { owlSubclassOf<owlSubclassOf( A, V )>, owlClassAssertion<owlClassAssertion( X, V, true )>, owlUnionClass<owlUnionClass( C, V )> } --> owlSubclassOf<owlSubclassOf( A, C )>, owlClassAssertion<owlClassAssertion( X, C, true )>
owlUnionOf<owlUnionOf( C, S )> { owlUnionOf<owlUnionOf( C, S )> } --> owlEquivalentClass<owlEquivalentClass( C1, C2 )>, owlUnionOfLoop<owlUnionOfLoop( C, ( ( *S ) . begin(  ) ), ( ( *S ) . end(  ) ) )>
owlIntersectionClass<owlIntersectionClass( C, V, I )> { intersectionSubclassCheck<intersectionSubclassCheck( C, A, I )>, owlSubclassOf<owlSubclassOf( C2, C1 )>, owlCandidatsIntersection<owlCandidatsIntersection( X, C, I )>, owlClassAssertion<owlClassAssertion( X, V, true )>, owlIntersectionClass<owlIntersectionClass( C, V, I )> } --> intersectionSubclassCheck<intersectionSubclassCheck( C, A, 1 )>, owlSubclassOf<owlSubclassOf( C2, Component )>, owlClassAssertion<owlClassAssertion( X, C1, true )>, owlCandidatsIntersection<owlCandidatsIntersection( X, C, 0 )>
intersectionSubclassCheck<intersectionSubclassCheck( X, C, I )> { owlIntersectionOfLoop<owlIntersectionOfLoop( C, ITEND, ITEND, N )>, owlSubclassOf<owlSubclassOf( A, V )>, owlIntersectionClass<owlIntersectionClass( C, V, I )>, intersectionSubclassCheck<intersectionSubclassCheck( X, C, I )> } --> owlSubclassOf<owlSubclassOf( A, C )>, intersectionSubclassCheck<intersectionSubclassCheck( C, A, ( I + 1 ) )>
owlIntersectionOfLoop<owlIntersectionOfLoop( C, IT, ITEND, I )> { intersectionSubclassCheck<intersectionSubclassCheck( C, A, N )>, owlCandidatsIntersection<owlCandidatsIntersection( X, C, I )>, owlIntersectionOfLoop<owlIntersectionOfLoop( C, IT, ITEND, I )> } --> owlSubclassOf<owlSubclassOf( A, C )>, owlClassAssertion<owlClassAssertion( X, C, true )>, owlIntersectionOfLoop<owlIntersectionOfLoop( C, ( std :: next( ( *IT ) ) ), ITEND, ( I + 1 ) )>, owlIntersectionClass<owlIntersectionClass( C, ( *( *IT ) ), I )>
owlInverseFunctionalObjectProperty<owlInverseFunctionalObjectProperty( P )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Z )>, owlInverseFunctionalObjectProperty<owlInverseFunctionalObjectProperty( P )> } --> owlSameIndividual<owlSameIndividual( X, Y )>
owlObjectAllValuesFrom<owlObjectAllValuesFrom( C, P, Y )> { owlObjectAllValuesFrom<owlObjectAllValuesFrom( C, P, Y )> } -->
owlDataAllValuesFrom<owlDataAllValuesFrom( C, P, DR )> { owlDataAllValuesFrom<owlDataAllValuesFrom( C, P, DR )> } -->
queryEngineeringStudentsWithId<queryEngineeringStudentsWithId( URIE, URIF, URIG, URIH, URIK, get_next_id(  ) )> { logicalName<logicalName( URIE, E )> } --> queryEngineeringStudents<queryEngineeringStudents( E, F, G, H, K, ID )>
owlSubclassOf<owlSubclassOf( A, B )> { classification<classification(  )>, querySubClassOfClass<querySubClassOfClass( X, Y )>, owlSubclassOf<owlSubclassOf( A, B )>, owlSubObjectPropertyOf<owlSubObjectPropertyOf( P1, P2 )>, owlObjectPropertyRange<owlObjectPropertyRange( P, C1 )>, owlClassAssertion<owlClassAssertion( X, A, true )>, querySubClassOf<querySubClassOf( X )>, querySuperClassOfClass<querySuperClassOfClass( X, Y )>, owlIntersectionClass<owlIntersectionClass( C1, Component, _ )>, owlObjectPropertyDomain<owlObjectPropertyDomain( P, C1 )>, intersectionSubclassCheck<intersectionSubclassCheck( C, A, I )>, owlHasValueObject<owlHasValueObject( C, P, A )>, owlUnionClass<owlUnionClass( C, V )>, owlObjectSomeValuesFrom<owlObjectSomeValuesFrom( SV, P, Y2 )>, logicalName<logicalName( URIY, Y )>, querySuperClassOf<querySuperClassOf( X )> } --> querySubClassOf<querySubClassOf( Y )>, resultClassification<resultClassification( URIX, URIY )>, built-in<afficher( "true" )>, queryEquivalentClass<queryEquivalentClass( X )>, querySuperClassOf<querySuperClassOf( Y )>, intersectionSubclassCheck<intersectionSubclassCheck( C, A, 1 )>, res<res( URIY )>, owlObjectPropertyDomain<owlObjectPropertyDomain( P, C2 )>, owlEquivalentClass<owlEquivalentClass( A, B )>, owlSubclassOf<owlSubclassOf( A, C )>, owlClassAssertion<owlClassAssertion( X, B, true )>, owlObjectPropertyRange<owlObjectPropertyRange( P, C2 )>, owlClass<owlClass( C1 )>
querySuperClassOfUri<querySuperClassOfUri( URI )> { logicalName<logicalName( URIC, X )>, querySuperClassOfUri<querySuperClassOfUri( URI )> } --> res<res( URIC )>, querySuperClassOf<querySuperClassOf( X )>
queryObjAssertionSubjectUri<queryObjAssertionSubjectUri( URIP, URIO )> { queryObjAssertionSubjectUri<queryObjAssertionSubjectUri( URIP, URIO )> } --> queryObjAssertionSubjectWithId<queryObjAssertionSubjectWithId( URIP, URIO, get_next_id(  ) )>
owlDataPropertyRange<owlDataPropertyRange( P, R )> { owlDataPropertyAssertion<owlDataPropertyAssertion( _, P, Y )>, owlSubDataPropertyOf<owlSubDataPropertyOf( P1, P2 )>, owlDataPropertyRange<owlDataPropertyRange( P, R )> } --> owlDataPropertyRange<owlDataPropertyRange( P1, C )>
querySuperClassOfClass<querySuperClassOfClass( X, Y )> { owlSubclassOf<owlSubclassOf( Y, X )>, querySuperClassOfClass<querySuperClassOfClass( X, Y )> } --> built-in<afficher( "true" )>
owlReflexiveObjectProperty<owlReflexiveObjectProperty( P )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )>, owlReflexiveObjectProperty<owlReflexiveObjectProperty( P )> } --> owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, X )>
querySuperClassOf<querySuperClassOf( X )> { logicalName<logicalName( URIY, Y )>, owlSubclassOf<owlSubclassOf( X, Y )>, querySuperClassOf<querySuperClassOf( X )> } --> res<res( URIY )>, queryEquivalentClass<queryEquivalentClass( X )>, querySuperClassOf<querySuperClassOf( Y )>
owlAsymmetricObjectProperty<owlAsymmetricObjectProperty( P )> { owlObjectPropertyAssertion<owlObjectPropertyAssertion( X, P, Y )>, owlAsymmetricObjectProperty<owlAsymmetricObjectProperty( P )> } --> owlNegativeObjectAssertion<owlNegativeObjectAssertion( Y, P, X )>
querySubClassOf<querySubClassOf( X )> { logicalName<logicalName( URIY, Y )>, owlSubclassOf<owlSubclassOf( Y, X )>, querySubClassOf<querySubClassOf( X )> } --> res<res( URIY )>, queryEquivalentClass<queryEquivalentClass( X )>, querySubClassOf<querySubClassOf( Y )>
querySubClassOfUri<querySubClassOfUri( URI )> { logicalName<logicalName( URIC, X )>, querySubClassOfUri<querySubClassOfUri( URI )> } --> res<res( URIC )>, querySubClassOf<querySubClassOf( X )>
queryClassificationUri<queryClassificationUri( URI )> { logicalName<logicalName( URIX, X )>, queryClassificationUri<queryClassificationUri( URI )> } --> queryClassification<queryClassification( X )>

(constraint) owlPrefix( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) owlClass( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlDataProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlNamedIndividual( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlSubclassOf( ( ?int ), ( ?int ) ), indexes: { <0,1>, <0>, <1> }, persistent
(constraint) owlEquivalentClass( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1> }, persistent
(constraint) owlSubDataPropertyOf( ( ?int ), ( ?int ) ), indexes: { <0>, <1>, <0,1> }, persistent
(constraint) owlSubObjectPropertyOf( ( ?int ), ( ?int ) ), indexes: { <0>, <1>, <0,1> }, persistent
(constraint) owlEquivalentDataProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) owlEquivalentObjectProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) owlObjectPropertyDomain( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1>, <1> }, persistent
(constraint) owlDataPropertyDomain( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1> }, persistent
(constraint) owlObjectPropertyRange( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1>, <1> }, persistent
(constraint) owlClassAssertion( ( ?int ), ( ?int ), ( +bool ) ), indexes: { <0,2>, <1,2>, <0,1,2>, <2>, <0> }, persistent
(constraint) owlDisjointClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) owlNegativeObjectAssertion( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0,1,2> }, persistent
(constraint) owlObjectPropertyAssertion( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0,1>, <2>, <0,1,2>, <1>, <1,2>, <0,2>, <0> }, persistent
(constraint) owlSameIndividual( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1>, <1> }, persistent
(constraint) owlDifferentIndividual( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) owlInverseObjectProperty( ( ?int ), ( ?int ) ), indexes: { <0,1>, <0> }, persistent
(constraint) owlSymmetricObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlAsymmetricObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlDisjointObjectProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) owlDisjointDataProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) owlReflexiveObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlIrreflexiveObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlFunctionalObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlFunctionalDataProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlInverseFunctionalObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlTransitiveObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint) owlDataPropertyAssertion( ( ?int ), ( ?int ), ( +Value ) ), indexes: { <0>, <0,1>, <0,1,2>, <0,2>, <1,2>, <1>, <2> }, persistent
(constraint) owlNegativeDataAssertion( ( ?int ), ( ?int ), ( +Value ) ), indexes: { <0,1,2> }, persistent
(constraint) owlDataPropertyRange( ( ?int ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0>, <0,1> }, persistent
(constraint) owlUnionClass( ( ?int ), ( ?int ) ), indexes: { <1>, <0,1> }, persistent
(constraint) owlUnionOf( ( ?int ), ( +LogicalVarSet ) ), indexes: { <0,1>, <1> }, persistent
(constraint) ##owlUnionOfLoop( ( ?int ), ( +LogicalVarSetIterator ), ( +LogicalVarSetIterator ) ), persistent
(constraint) owlIntersectionOf( ( ?int ), ( +LogicalVarSet ) ), indexes: { <0,1> }, persistent
(constraint) owlIntersectionClass( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,2>, <0,1,2>, <1,2>, <1>, <0> }, persistent
(constraint) owlIntersectionOfLoop( ( ?int ), ( +LogicalVarSetIterator ), ( +LogicalVarSetIterator ), ( +int ) ), indexes: { <0,3>, <0,1,2,3> }, persistent
(constraint) intersectionSubclassCheck( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1,2>, <0,2> }, persistent
(constraint) owlCandidatsIntersection( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1,2>, <1,2> }, persistent
(constraint) owlObjectAllValuesFrom( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0,1,2> }, persistent
(constraint) owlDataAllValuesFrom( ( ?int ), ( ?int ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0,1,2> }, persistent
(constraint) owlObjectSomeValuesFrom( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <2>, <0>, <1,2>, <0,1,2> }, persistent
(constraint) owlDataSomeValuesFrom( ( ?int ), ( ?int ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0>, <1>, <0,1,2> }, persistent
(constraint) owlDataValue( ( +Value ), ( +( std :: string ) ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0,1>, <0>, <1>, <0,1,2> }, persistent
(constraint) owlComplementOf( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) owlObjectMaxCardinality( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,2>, <0,1,2>, <1,2> }, persistent
(constraint) owlDataMaxCardinality( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,2>, <0,1,2>, <1,2> }, persistent
(constraint) owlHasValueObject( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0>, <2>, <0,1,2>, <0,1>, <1,2> }, persistent
(constraint) owlOneOf( ( ?int ), ( +LogicalVarSet ) ), indexes: { <0,1> }, persistent
(constraint) ##owlOneOfLoop( ( ?int ), ( +LogicalVarSetIterator ), ( +LogicalVarSetIterator ) ), indexes: { <0,1,2> }, persistent
(constraint) owlObjectPropertyChain( ( ?int ), ( ?int ), ( +int ), ( +int ) ), indexes: { <0,3>, <1,2>, <1> }, persistent
(constraint) constructPropertyChain( ( ?int ), ( +int ), ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1,2,3,4>, <0,3,4>, <0,4> }, persistent
(constraint) owlHasKey( ( ?int ), ( ?int ), ( +int ), ( +int ) ), indexes: { <0,2>, <0,1,2,3>, <0,2,3> }, persistent
(constraint) owlHasKeyCheck( ( ?int ), ( ?int ), ( ?int ), ( +int ), ( +int ) ), indexes: { <1,2>, <0,3,4>, <0,1,2,3,4> }, persistent
(constraint) querySuperClassOfUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint) querySuperClassOfClassUri( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
(constraint) querySubClassOfUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint) querySubClassOfClassUri( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
(constraint) querySuperClassOf( ( ?int ) ), indexes: { <0> }, persistent
(constraint) querySuperClassOfReal( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) querySubClassOf( ( ?int ) ), indexes: { <0> }, persistent
(constraint) ##querySubClassOfClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) ##querySuperClassOfClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) queryClassification( ( ?int ) ), indexes: { <0> }, persistent
(constraint) queryClassificationReal( ( ?int ) ), indexes: { <0> }, persistent
(constraint) queryClassificationUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint) queryClassificationTemp( ( ?int ) ), indexes: { <0> }, persistent
(constraint) queryClassificationTempUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint) queryInstanceURI( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
(constraint) ##queryInstance( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) ##queryInstancesURI( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint) queryInstances( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
(constraint) ##queryObjAssertionUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint) queryObjAssertion( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
(constraint) ##querySubjectByObjectUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint) querySubjectByObject( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
(constraint) ##queryDataAssertionUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint) queryDataAssertion( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
(constraint) ##queryEngineeringStudentsUri( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ) ), persistent
(constraint) queryEngineeringStudents( ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( +int ) ), indexes: { <0>, <0,1>, <0,2>, <0,3,4> }, persistent
(constraint) ##queryComplexStudentsUri( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ) ), persistent
(constraint) queryComplexStudents( ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1>, <0,1,2>, <0,1,3>, <0,1,4> }, persistent
(constraint) ##queryObjAssertionSubjectUri( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
(constraint) queryObjAssertionSubject( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1>, <0,1,2> }, persistent
(constraint) queryObjAssertionClassUri( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) queryObjAssertionClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) queryEquivalentClass( ( ?int ) ), indexes: { <0> }, persistent
(constraint) queryEquivalentClassReal( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint) res( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint) resultRealisation( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
(constraint) classification(  ), persistent
(constraint) resultClassification( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0>, <0,1> }, persistent
(constraint) queryFullUri( ( ?int ) ), indexes: { <0> }, persistent
(constraint) logicalName( ( +( std :: string ) ), ( ?int ) ), indexes: { <0>, <1>, <0,1> }, persistent
(constraint) realisation(  ), persistent
(constraint) queryisMemberOf(  ), persistent
(constraint) ResultVec( ( +StringSet ), ( +int ) ), indexes: { <0,1> }, persistent
(constraint) ##queryInstancesWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
(constraint) ##queryObjAssertionWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
(constraint) ##queryDataAssertionWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
(constraint) ##querySubjectByObjectWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
(constraint) ##queryObjAssertionSubjectWithId( ( +( std :: string ) ), ( +( std :: string ) ), ( +int ) ), indexes: { <0>, <1> }, persistent
(constraint) ##queryEngineeringStudentsWithId( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +int ) ), indexes: { <0>, <1>, <2>, <3>, <4> }, persistent
(constraint) ##queryComplexStudentsWithId( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +int ) ), indexes: { <0>, <1>, <2>, <3>, <4> }, persistent
(rule) owlPrefix( X, Y ) \ owlPrefix( X, Y ) <=> true ;;
(rule) owlClass( C ) \ owlClass( C ) <=> true ;;
(rule) owlObjectProperty( P ) \ owlObjectProperty( P ) <=> true ;;
(rule) owlDataProperty( P ) \ owlDataProperty( P ) <=> true ;;
(rule) owlNamedIndividual( C ) \ owlNamedIndividual( C ) <=> true ;;
(rule) owlSubclassOf( A, B ) \ owlSubclassOf( A, B ) <=> true ;;
(rule) owlEquivalentClass( A, B ) \ owlEquivalentClass( A, B ) <=> true ;;
(rule) owlSubDataPropertyOf( A, B ) \ owlSubDataPropertyOf( A, B ) <=> true ;;
(rule) owlSubObjectPropertyOf( A, B ) \ owlSubObjectPropertyOf( A, B ) <=> true ;;
(rule) owlEquivalentDataProperty( A, B ) \ owlEquivalentDataProperty( A, B ) <=> true ;;
(rule) owlEquivalentObjectProperty( A, B ) \ owlEquivalentObjectProperty( A, B ) <=> true ;;
(rule) owlObjectPropertyDomain( P, C ) \ owlObjectPropertyDomain( P, C ) <=> true ;;
(rule) owlDataPropertyDomain( P, C ) \ owlDataPropertyDomain( P, C ) <=> true ;;
(rule) owlObjectPropertyRange( P, C ) \ owlObjectPropertyRange( P, C ) <=> true ;;
(rule) owlClassAssertion( X, A, B ) \ owlClassAssertion( X, A, B ) <=> true ;;
(rule) owlDisjointClass( A, B ) \ owlDisjointClass( A, B ) <=> true ;;
(rule) owlNegativeObjectAssertion( X, P, Y ) \ owlNegativeObjectAssertion( X, P, Y ) <=> true ;;
(rule) owlObjectPropertyAssertion( X, P, Y ) \ owlObjectPropertyAssertion( X, P, Y ) <=> true ;;
(rule) owlSameIndividual( X, Y ) \ owlSameIndividual( X, Y ) <=> true ;;
(rule) owlDifferentIndividual( X, Y ) \ owlDifferentIndividual( X, Y ) <=> true ;;
(rule) owlInverseObjectProperty( P1, P2 ) \ owlInverseObjectProperty( P1, P2 ) <=> true ;;
(rule) owlSymmetricObjectProperty( P ) \ owlSymmetricObjectProperty( P ) <=> true ;;
(rule) owlAsymmetricObjectProperty( P ) \ owlAsymmetricObjectProperty( P ) <=> true ;;
(rule) owlDisjointObjectProperty( A, B ) \ owlDisjointObjectProperty( A, B ) <=> true ;;
(rule) owlDisjointDataProperty( A, B ) \ owlDisjointDataProperty( A, B ) <=> true ;;
(rule) owlReflexiveObjectProperty( P ) \ owlReflexiveObjectProperty( P ) <=> true ;;
(rule) owlIrreflexiveObjectProperty( P ) \ owlIrreflexiveObjectProperty( P ) <=> true ;;
(rule) owlFunctionalObjectProperty( P ) \ owlFunctionalObjectProperty( P ) <=> true ;;
(rule) owlFunctionalDataProperty( P ) \ owlFunctionalDataProperty( P ) <=> true ;;
(rule) owlInverseFunctionalObjectProperty( P ) \ owlInverseFunctionalObjectProperty( P ) <=> true ;;
(rule) owlTransitiveObjectProperty( P ) \ owlTransitiveObjectProperty( P ) <=> true ;;
(rule) owlDataPropertyAssertion( X, P, Y ) \ owlDataPropertyAssertion( X, P, Y ) <=> true ;;
(rule) owlNegativeDataAssertion( X, P, Y ) \ owlNegativeDataAssertion( X, P, Y ) <=> true ;;
(rule) owlDataPropertyRange( P, R ) \ owlDataPropertyRange( P, R ) <=> true ;;
(rule) owlUnionClass( C, V ) \ owlUnionClass( C, V ) <=> true ;;
(rule) owlUnionOf( C, S ) \ owlUnionOf( C, S ) <=> true ;;
(rule) owlIntersectionOf( C, S ) \ owlIntersectionOf( C, S ) <=> true ;;
(rule) owlIntersectionClass( C, V, I ) \ owlIntersectionClass( C, V, I ) <=> true ;;
(rule) owlIntersectionOfLoop( C, IT, ITEND, I ) \ owlIntersectionOfLoop( C, IT, ITEND, I ) <=> true ;;
(rule) owlCandidatsIntersection( X, C, I ) \ owlCandidatsIntersection( X, C, I ) <=> true ;;
(rule) intersectionSubclassCheck( X, C, I ) \ intersectionSubclassCheck( X, C, I ) <=> true ;;
(rule) owlObjectAllValuesFrom( C, P, Y ) \ owlObjectAllValuesFrom( C, P, Y ) <=> true ;;
(rule) owlDataAllValuesFrom( C, P, DR ) \ owlDataAllValuesFrom( C, P, DR ) <=> true ;;
(rule) owlObjectSomeValuesFrom( C, P, Y ) \ owlObjectSomeValuesFrom( C, P, Y ) <=> true ;;
(rule) owlDataSomeValuesFrom( C, P, DR ) \ owlDataSomeValuesFrom( C, P, DR ) <=> true ;;
(rule) owlDataValue( V, S, T ) \ owlDataValue( V, S, T ) <=> true ;;
(rule) owlComplementOf( A, NOTA ) \ owlComplementOf( A, NOTA ) <=> true ;;
(rule) querySuperClassOfUri( URI ) \ querySuperClassOfUri( URI ) <=> true ;;
(rule) querySuperClassOf( X ) \ querySuperClassOf( X ) <=> true ;;
(rule) querySubClassOf( X ) \ querySubClassOf( X ) <=> true ;;
(rule) querySubClassOfUri( URI ) \ querySubClassOfUri( URI ) <=> true ;;
(rule) querySubClassOfClass( X, Y ) \ querySubClassOfClass( X, Y ) <=> true ;;
(rule) querySubClassOfClassUri( URIX, URIY ) \ querySubClassOfClassUri( URIX, URIY ) <=> true ;;
(rule) querySuperClassOfClass( X, Y ) \ querySuperClassOfClass( X, Y ) <=> true ;;
(rule) querySuperClassOfClassUri( URIX, URIY ) \ querySuperClassOfClassUri( URIX, URIY ) <=> true ;;
(rule) queryClassification( X ) \ queryClassification( X ) <=> true ;;
(rule) queryClassificationUri( URI ) \ queryClassificationUri( URI ) <=> true ;;
(rule) queryClassificationTemp( X ) \ queryClassificationTemp( X ) <=> true ;;
(rule) queryClassificationTempUri( URI ) \ queryClassificationTempUri( URI ) <=> true ;;
(rule) queryInstanceURI( URIX, URIC ) \ queryInstanceURI( URIX, URIC ) <=> true ;;
(rule) queryInstance( X, C ) \ queryInstance( X, C ) <=> true ;;
(rule) queryInstancesURI( URIC ) \ queryInstancesURI( URIC ) <=> true ;;
(rule) queryInstances( C, ID ) \ queryInstances( C, ID ) <=> true ;;
(rule) queryObjAssertionUri( URIP ) \ queryObjAssertionUri( URIP ) <=> true ;;
(rule) queryObjAssertion( P, ID ) \ queryObjAssertion( P, ID ) <=> true ;;
(rule) querySubjectByObjectUri( URIP ) \ querySubjectByObjectUri( URIP ) <=> true ;;
(rule) querySubjectByObject( P, ID ) \ querySubjectByObject( P, ID ) <=> true ;;
(rule) queryDataAssertionUri( URIP ) \ queryDataAssertionUri( URIP ) <=> true ;;
(rule) queryDataAssertion( P, ID ) \ queryDataAssertion( P, ID ) <=> true ;;
(rule) queryObjAssertionSubjectUri( URIP, URIO ) \ queryObjAssertionSubjectUri( URIP, URIO ) <=> true ;;
(rule) queryObjAssertionSubject( P, O, ID ) \ queryObjAssertionSubject( P, O, ID ) <=> true ;;
(rule) queryObjAssertionClassUri( URIP, URIC ) \ queryObjAssertionClassUri( URIP, URIC ) <=> true ;;
(rule) queryObjAssertionClass( P, C ) \ queryObjAssertionClass( P, C ) <=> true ;;
(rule) queryObjAssertionSubject( P, O, ID ) \ queryObjAssertionSubject( P, O, ID ) <=> true ;;
(rule) queryEquivalentClass( X ) \ queryEquivalentClass( X ) <=> true ;;
(rule) queryClassificationReal( X ) \ queryClassificationReal( X ) <=> true ;;
(rule) querySuperClassOfReal( I, C ) \ querySuperClassOfReal( I, C ) <=> true ;;
(rule) queryEquivalentClassReal( I, X ) \ queryEquivalentClassReal( I, X ) <=> true ;;
(rule) res( X ) \ res( X ) <=> true ;;
(rule) resultRealisation( X, Y ) \ resultRealisation( X, Y ) <=> true ;;
(rule) resultClassification( X, Y ) \ resultClassification( X, Y ) <=> true ;;
(rule) ResultVec( S, ID ) \ ResultVec( S, ID ) <=> true ;;
(rule) queryFullUri( X ) \ queryFullUri( X ) <=> true ;;
(rule) logicalName( URI, X ) \ logicalName( URI, X ) <=> true ;;
(rule) owlObjectMaxCardinality( C, P, N ) \ owlObjectMaxCardinality( C, P, N ) <=> true ;;
(rule) owlDataMaxCardinality( C, P, N ) \ owlDataMaxCardinality( C, P, N ) <=> true ;;
(rule) owlHasValueObject( C, P, Y ) \ owlHasValueObject( C, P, Y ) <=> true ;;
(rule) owlOneOf( C, S ) \ owlOneOf( C, S ) <=> true ;;
(rule) owlOneOfLoop( C, IT, ITEND ) \ owlOneOfLoop( C, IT, ITEND ) <=> true ;;
(rule) classification(  ) \ classification(  ) <=> true ;;
(rule) DisjointClass @ owlDisjointClass( A, B ), owlClassAssertion( X, A, true ), owlClassAssertion( X, B, true ) <=> failure ;;
(rule) NegativeObjectAssertion @ owlNegativeObjectAssertion( X, P, Y ), owlObjectPropertyAssertion( X, P, Y ) <=> failure ;;
(rule) DisjointObjProperty @ owlDisjointObjectProperty( A, B ), owlObjectPropertyAssertion( X, A, Y ), owlObjectPropertyAssertion( X, B, Y ) <=> failure ;;
(rule) DisjointDataProperty @ owlDisjointDataProperty( A, B ), owlDataPropertyAssertion( X, A, Y ), owlDataPropertyAssertion( X, B, Y ) <=> failure ;;
(rule) NegativeDataAssertion @ owlNegativeDataAssertion( X, P, Y ), owlDataPropertyAssertion( X, P, Y ) <=> failure ;;
(rule) irreflexiveProperty @ owlIrreflexiveObjectProperty( P ), owlObjectPropertyAssertion( X, P, X ) <=> failure ;;
(rule) complementOf @ owlComplementOf( A, NOTA ), owlClassAssertion( X, A, true ), owlClassAssertion( X, NOTA, true ) <=> failure ;;
(rule) owlSubclassOf( C1, C2 ) ==> ( owlClass( C1 ), owlClass( C2 ) ) ;;
(rule) owlClassAssertion( X, C, true ) ==> ( owlClass( C ), owlNamedIndividual( X ) ) ;;
(rule) owlSubclassOf( A, B ), owlSubclassOf( B, C ) ==> different( A, B, C ) | owlSubclassOf( A, C ) ;;
(rule) owlClass( C ) ==> owlEquivalentClass( C, C ) ;;
(rule) owlSubclassOf( A, B ), owlSubclassOf( B, A ) ==> ( !( A == B ) ) | owlEquivalentClass( A, B ) ;;
(rule) owlClass( C ), logicalName( URIC, C ), logicalName( owlThing, OwlThingVar ) ==> ( !( URIC == "http://www.w3.org/2002/07/owl#Thing" ) ) | owlSubclassOf( C, OwlThingVar ) ;;
(rule) owlClass( C ), logicalName( URIC, C ), logicalName( owlNothing, OwlNothingVar ) ==> ( !( URIC == owlNothing ) ) | owlSubclassOf( OwlNothingVar, C ) ;;
(rule) owlObjectProperty( P ) ==> ( owlSubObjectPropertyOf( P, P ), owlEquivalentObjectProperty( P, P ) ) ;;
(rule) owlDataProperty( P ) ==> ( owlEquivalentDataProperty( P, P ), owlSubDataPropertyOf( P, P ) ) ;;
(rule) owlSubObjectPropertyOf( A, B ), owlSubObjectPropertyOf( B, C ) ==> different( A, B, C ) | owlSubObjectPropertyOf( A, C ) ;;
(rule) owlSubDataPropertyOf( A, B ), owlSubDataPropertyOf( B, C ) ==> different( A, B, C ) | owlSubDataPropertyOf( A, C ) ;;
(rule) owlEquivalentObjectProperty( A, B ) ==> ( !( A == B ) ) | ( owlSubObjectPropertyOf( A, B ), owlSubObjectPropertyOf( B, A ) ) ;;
(rule) owlEquivalentDataProperty( A, B ) ==> ( !( A == B ) ) | ( owlSubDataPropertyOf( A, B ), owlSubDataPropertyOf( B, A ) ) ;;
(rule) owlSubObjectPropertyOf( A, B ), owlSubObjectPropertyOf( B, A ) ==> ( !( A == B ) ) | owlEquivalentObjectProperty( A, B ) ;;
(rule) owlSubDataPropertyOf( A, B ), owlSubDataPropertyOf( B, A ) ==> ( !( A == B ) ) | owlEquivalentDataProperty( A, B ) ;;
(rule) owlObjectPropertyDomain( P, C1 ), owlSubclassOf( C1, C2 ) ==> ( !( C1 == C2 ) ) | owlObjectPropertyDomain( P, C2 ) ;;
(rule) owlObjectPropertyDomain( P2, C ), owlSubObjectPropertyOf( P1, P2 ) ==> ( !( P1 == P2 ) ) | owlObjectPropertyDomain( P1, C ) ;;
(rule) owlObjectPropertyRange( P, C1 ), owlSubclassOf( C1, C2 ) ==> ( !( C1 == C2 ) ) | owlObjectPropertyRange( P, C2 ) ;;
(rule) owlObjectPropertyRange( P2, C ), owlSubObjectPropertyOf( P1, P2 ) ==> ( !( P1 == P2 ) ) | owlObjectPropertyRange( P1, C ) ;;
(rule) owlDataPropertyDomain( P2, C ), owlSubDataPropertyOf( P1, P2 ) ==> ( !( P1 == P2 ) ) | owlDataPropertyDomain( P1, C ) ;;
(rule) owlDataPropertyRange( P2, C ), owlSubDataPropertyOf( P1, P2 ) ==> ( !( P1 == P2 ) ) | owlDataPropertyRange( P1, C ) ;;
(rule) DataPropertyDomain @ owlDataPropertyDomain( P, DP ), owlDataPropertyAssertion( X, P, _ ) ==> owlClassAssertion( X, DP, true ) ;;
(rule) DataPropertyRange @ owlDataPropertyRange( P, DR ), owlDataPropertyAssertion( _, P, Y ) <=> invalidType( DR, Y ) | failure ;;
(rule) subclass @ owlSubclassOf( A, B ), owlClassAssertion( X, A, true ) ==> ( !( A == B ) ) | owlClassAssertion( X, B, true ) ;;
(rule) equivalentClass @ owlEquivalentClass( A, B ), owlClassAssertion( X, A, true ) ==> ( !( A == B ) ) | owlClassAssertion( X, B, true ) ;;
(rule) owlEquivalentClass( A, B ) ==> ( !( A == B ) ) | ( owlSubclassOf( A, B ), owlSubclassOf( B, A ) ) ;;
(rule) subObjproperty @ owlSubObjectPropertyOf( P2, P1 ), owlObjectPropertyAssertion( X, P2, Y ) ==> ( !( P2 == P1 ) ) | owlObjectPropertyAssertion( X, P1, Y ) ;;
(rule) subDataProperty @ owlSubDataPropertyOf( P2, P1 ), owlDataPropertyAssertion( X, P2, Y ) ==> ( !( P2 == P1 ) ) | owlDataPropertyAssertion( X, P1, Y ) ;;
(rule) objectPropertydomain @ owlObjectPropertyDomain( P, DP ), owlObjectPropertyAssertion( X, P, Y ) ==> owlClassAssertion( X, DP, true ) ;;
(rule) objectPropertyCoDomain @ owlObjectPropertyRange( P, DP ), owlObjectPropertyAssertion( X, P, Y ) ==> owlClassAssertion( Y, DP, true ) ;;
(rule) sameIndividual1 @ owlSameIndividual( X, Y ) ==> ( !( X == Y ) ) | owlSameIndividual( Y, X ) ;;
(rule) sameIndividual2 @ owlSameIndividual( X, Y ), owlSameIndividual( Y, Z ) ==> ( ( ( !( X == Y ) ) && ( !( Y == Z ) ) ) && ( !( X == Z ) ) ) | owlSameIndividual( X, Z ) ;;
(rule) sameIndividual3 @ owlSameIndividual( X, Y ), owlObjectPropertyAssertion( X, P, O ) ==> ( !( X == Y ) ) | owlObjectPropertyAssertion( Y, P, O ) ;;
(rule) sameIndividual4 @ owlSameIndividual( X, Y ), owlDataPropertyAssertion( X, P, O ) ==> ( !( X == Y ) ) | owlDataPropertyAssertion( Y, P, O ) ;;
(rule) sameIndividual5 @ owlSameIndividual( O1, O2 ), owlObjectPropertyAssertion( X, P, O1 ) ==> ( !( O1 == O2 ) ) | owlObjectPropertyAssertion( X, P, O2 ) ;;
(rule) sameIndividual6 @ owlSameIndividual( X, Y ), owlClassAssertion( X, C, B ) ==> ( !( X == Y ) ) | owlClassAssertion( Y, C, B ) ;;
(rule) DifferentIndividual @ owlDifferentIndividual( X, Y ), owlSameIndividual( X, Y ) <=> failure ;;
(rule) inverseProperty @ owlInverseObjectProperty( P1, P2 ), owlObjectPropertyAssertion( X, P1, Y ) ==> owlObjectPropertyAssertion( Y, P2, X ) ;;
(rule) owlInverseObjectProperty( P1, P2 ) ==> owlInverseObjectProperty( P2, P1 ) ;;
(rule) symmetricProperty @ owlSymmetricObjectProperty( P ), owlObjectPropertyAssertion( X, P, Y ) ==> owlObjectPropertyAssertion( Y, P, X ) ;;
(rule) AsymmetricProperty1 @ owlAsymmetricObjectProperty( P ), owlObjectPropertyAssertion( X, P, Y ) ==> owlNegativeObjectAssertion( Y, P, X ) ;;
(rule) reflexiveProperty @ owlReflexiveObjectProperty( P ), owlObjectPropertyAssertion( X, P, Y ) ==> ( owlObjectPropertyAssertion( X, P, X ), owlObjectPropertyAssertion( Y, P, Y ) ) ;;
(rule) functionalObjProperty @ owlFunctionalObjectProperty( P ), owlObjectPropertyAssertion( X, P, Y ), owlObjectPropertyAssertion( X, P, Z ) ==> ( !( Y == Z ) ) | owlSameIndividual( Y, Z ) ;;
(rule) functionalDataProperty @ owlFunctionalDataProperty( P ), owlDataPropertyAssertion( X, P, Y ), owlDataPropertyAssertion( X, P, Z ) <=> ( !( Y == Z ) ) | failure ;;
(rule) inverseFunctional @ owlInverseFunctionalObjectProperty( P ), owlObjectPropertyAssertion( X, P, Z ), owlObjectPropertyAssertion( Y, P, Z ) ==> ( !( X == Y ) ) | owlSameIndividual( X, Y ) ;;
(rule) owlDataPropertyAssertion( X, P, Y ) ==> owlDataValue( Y, ( ( *Y ) . val ), ( ( *Y ) . typeVal ) ) ;;
(rule) owlUnionOf( C, S ) ==> owlUnionOfLoop( C, ( ( *S ) . begin(  ) ), ( ( *S ) . end(  ) ) ) ;;
(rule) owlUnionOfLoop( C, ITEND, ITEND ) <=> success ;;
(rule) owlUnionOfLoop( C, IT, ITEND ) <=> ( owlUnionClass( C, ( *( *IT ) ) ), owlUnionOfLoop( C, ( std :: next( ( *IT ) ) ), ITEND ) ) ;;
(rule) owlClassAssertion( X, V, true ) \ owlUnionClass( C, V ) <=> owlClassAssertion( X, C, true ) ;;
(rule) owlUnionClass( C, V ), owlSubclassOf( A, V ) ==> ( !( C == A ) ) | owlSubclassOf( A, C ) ;;
(rule) owlUnionOf( C1, S ), owlUnionOf( C2, S ) ==> owlEquivalentClass( C1, C2 ) ;;
(rule) r0 @ owlIntersectionOf( C, S ) ==> owlIntersectionOfLoop( C, ( ( *S ) . begin(  ) ), ( ( *S ) . end(  ) ), 0 ) ;;
(rule) r1 @ owlIntersectionOfLoop( C, IT, ITEND, I ) <=> ( !( IT == ITEND ) ) | ( owlIntersectionClass( C, ( *( *IT ) ), I ), owlIntersectionOfLoop( C, ( std :: next( ( *IT ) ) ), ITEND, ( I + 1 ) ) ) ;;
(rule) r2 @ owlClassAssertion( X, V, true ), owlIntersectionClass( C, V, 0 ) ==> owlCandidatsIntersection( X, C, 0 ) ;;
(rule) r3 @ owlIntersectionClass( C, V, I ), owlCandidatsIntersection( X, C, I ), owlClassAssertion( X, V, true ) ==> owlCandidatsIntersection( X, C, ( I + 1 ) ) ;;
(rule) r5 @ owlCandidatsIntersection( X, C, I ), owlIntersectionOfLoop( C, ITEND, ITEND, I ) ==> owlClassAssertion( X, C, true ) ;;
(rule) r6 @ owlIntersectionClass( C, C1, _ ), owlClassAssertion( X, C, true ) ==> owlClassAssertion( X, C1, true ) ;;
(rule) r7 @ owlIntersectionClass( C1, Component, _ ), owlSubclassOf( C2, C1 ) ==> ( !( C1 == C2 ) ) | owlSubclassOf( C2, Component ) ;;
(rule) intersectionSubclassCheck( C, A, I ) \ intersectionSubclassCheck( C, A, I ) <=> true ;;
(rule) r8a @ owlSubclassOf( A, V ), owlIntersectionClass( C, V, 0 ) ==> intersectionSubclassCheck( C, A, 1 ) ;;
(rule) r8b @ owlIntersectionClass( C, V, I ), owlSubclassOf( A, V ), intersectionSubclassCheck( C, A, I ) ==> ( I > 0 ) | intersectionSubclassCheck( C, A, ( I + 1 ) ) ;;
(rule) r8c @ owlIntersectionOfLoop( C, ITEND, ITEND, N ) \ intersectionSubclassCheck( C, A, N ) <=> owlSubclassOf( A, C ) ;;
(rule) owlComplementOf( A, NOTA ), owlNamedIndividual( X ) ==> owlClassAssertion( X, NOTA, false ) ;;
(rule) owlClassAssertion( X, NOTA, true ) \ owlClassAssertion( X, NOTA, false ) <=> true ;;
(rule) owlComplementOf( A, NOTA ), owlClassAssertion( X, A, true ) \ owlClassAssertion( X, NOTA, false ) <=> true ;;
(rule) owlObjectSomeValuesFrom( C1, P, Y ), owlObjectSomeValuesFrom( C2, P, Y ) ==> ( !( C1 == C2 ) ) | owlEquivalentClass( C1, C2 ) ;;
(rule) owlObjectSomeValuesFrom( C, P, Y ), owlObjectPropertyAssertion( U, P, V ), owlClassAssertion( V, Y, true ) ==> owlClassAssertion( U, C, true ) ;;
(rule) owlObjectSomeValuesFrom( C, P, Y ), owlClassAssertion( U, C, true ) ==> ( owlObjectPropertyAssertion( U, P, V ), logicalName( emptyString, V ), owlClassAssertion( V, Y, true ) ) ;;
(rule) owlObjectPropertyAssertion( U, P, W ), logicalName( URI, W ), owlClassAssertion( W, Y, true ) \ owlObjectPropertyAssertion( U, P, V ), logicalName( emptyString, V ), owlClassAssertion( V, Y, true ) <=> ( !( URI == emptyString ) ) | success ;;
(rule) owlDataSomeValuesFrom( C, P, DR ), owlDataPropertyAssertion( U, P, V ) ==> ( !invalidType( DR, V ) ) | owlClassAssertion( U, C, true ) ;;
(rule) owlDataSomeValuesFrom( C, P, DR ), owlClassAssertion( U, C, true ) ==> ( owlDataPropertyAssertion( U, P, createValue( emptyString, DR ) ), logicalName( emptyString, V ) ) ;;
(rule) owlDataPropertyAssertion( U, P, W ), owlDataValue( W, ValW, TypeW ) \ owlDataValue( V, emptyString, TypeV ), owlDataPropertyAssertion( U, P, V ) <=> ( sameDataType( TypeV, TypeW ) && ( !( ValW == emptyString ) ) ) | success ;;
(rule) owlObjectMaxCardinality( C, P, 0 ), owlClassAssertion( U, C, true ), owlObjectPropertyAssertion( U, P, _ ) <=> failure ;;
(rule) owlObjectMaxCardinality( C, P, 1 ), owlClassAssertion( U, C, true ), owlObjectPropertyAssertion( U, P, Y1 ), owlObjectPropertyAssertion( U, P, Y2 ) <=> ( !( Y1 == Y2 ) ) | owlSameIndividual( Y1, Y2 ) ;;
(rule) owlDataMaxCardinality( C, P, 0 ), owlClassAssertion( U, C, true ), owlDataPropertyAssertion( U, P, _ ) <=> failure ;;
(rule) owlDataMaxCardinality( C, P, 1 ), owlClassAssertion( U, C, true ), owlDataPropertyAssertion( U, P, Y1 ), owlDataPropertyAssertion( U, P, Y2 ) <=> ( !( Y1 == Y2 ) ) | failure ;;
(rule) owlHasValueObject( C, P, Y ), owlObjectProperty( P ), owlClassAssertion( U, C, true ) ==> owlObjectPropertyAssertion( U, P, Y ) ;;
(rule) owlHasValueObject( C, P, Y ), owlObjectPropertyAssertion( U, P, Y ) ==> owlClassAssertion( U, C, true ) ;;
(rule) hasValueSubsumption @ owlHasValueObject( C, P, A ), owlClassAssertion( A, Y, true ), owlObjectSomeValuesFrom( SV, P, Y ) ==> owlSubclassOf( C, SV ) ;;
(rule) hasValueSubsumptionClass @ owlHasValueObject( C, P, A ), owlClassAssertion( A, Y1, true ), owlSubclassOf( Y1, Y2 ), owlObjectSomeValuesFrom( SV, P, Y2 ) ==> owlSubclassOf( C, SV ) ;;
(rule) hasValueSubsumptionProp @ owlHasValueObject( C, P1, A ), owlSubObjectPropertyOf( P1, P2 ), owlClassAssertion( A, Y, true ), owlObjectSomeValuesFrom( SV, P2, Y ) ==> owlSubclassOf( C, SV ) ;;
(rule) hasValueSubsumptionPropClass @ owlHasValueObject( C, P1, A ), owlSubObjectPropertyOf( P1, P2 ), owlClassAssertion( A, Y1, true ), owlSubclassOf( Y1, Y2 ), owlObjectSomeValuesFrom( SV, P2, Y2 ) ==> owlSubclassOf( C, SV ) ;;
(rule) owlOneOf( C, S ) ==> owlOneOfLoop( C, ( ( *S ) . begin(  ) ), ( ( *S ) . end(  ) ) ) ;;
(rule) owlOneOfLoop( C, ITEND, ITEND ) <=> success ;;
(rule) owlOneOfLoop( C, IT, ITEND ) <=> ( owlClassAssertion( ( *( *IT ) ), C, true ), owlOneOfLoop( C, ( std :: next( ( *IT ) ) ), ITEND ) ) ;;
(rule) constructPropertyChain( PC, I, X, Y, N ) \ constructPropertyChain( PC, I, X, Y, N ) <=> true ;;
(rule) ObjectPropertyChain @ owlObjectPropertyChain( PC, P, 0, N ), owlObjectPropertyAssertion( X, P, Y ) ==> constructPropertyChain( PC, 0, X, Y, N ) ;;
(rule) chainStep @ owlObjectPropertyAssertion( Y, P, Z ), owlObjectPropertyChain( PC, P, J, N ), constructPropertyChain( PC, I, X, Y, N ) ==> ( ( I < N ) && equalIncrement( J, I ) ) | constructPropertyChain( PC, ( I + 1 ), X, Z, N ) ;;
(rule) finalChain @ constructPropertyChain( PC, N, X, Y, N ) <=> owlObjectPropertyAssertion( X, PC, Y ) ;;
(rule) owlHasKey( C, P, I, N ) \ owlHasKey( C, P, I, N ) <=> true ;;
(rule) owlHasKeyCheck( C, X, Y, I, N ) \ owlHasKeyCheck( C, X, Y, I, N ) <=> true ;;
(rule) owlHasKey( C, P, 0, N ), owlClassAssertion( X, C, true ), owlClassAssertion( Y, C, true ) ==> ( !( X == Y ) ) | owlHasKeyCheck( C, X, Y, 0, N ) ;;
(rule) owlObjectPropertyAssertion( X, P, V ), owlObjectPropertyAssertion( Y, P, V ), owlHasKey( C, P, I, N ) \ owlHasKeyCheck( C, X, Y, I, N ) <=> owlHasKeyCheck( C, X, Y, ( I + 1 ), N ) ;;
(rule) owlDataPropertyAssertion( X, P, V ), owlDataPropertyAssertion( Y, P, V ), owlHasKey( C, P, I, N ) \ owlHasKeyCheck( C, X, Y, I, N ) <=> owlHasKeyCheck( C, X, Y, ( I + 1 ), N ) ;;
(rule) owlHasKeyCheck( C, X, Y, N, N ) <=> owlSameIndividual( X, Y ) ;;
(rule) res( URIC ) ==> afficher( URIC ) ;;
(rule) querySuperClassOfUri( URIC ), logicalName( URIC, X ) ==> ( querySuperClassOf( X ), res( URIC ) ) ;;
(rule) querySuperClassOf( X ), owlSubclassOf( X, Y ), logicalName( URIY, Y ) ==> ( !( X == Y ) ) | ( querySuperClassOf( Y ), queryEquivalentClass( X ), res( URIY ) ) ;;
(rule) r_querySuperClassOfClassURI @ logicalName( URIX, X ), logicalName( URIY, Y ) \ querySuperClassOfClassUri( URIX, URIY ) <=> querySuperClassOfClass( X, Y ) ;;
(rule) owlSubclassOf( Y, X ) \ querySuperClassOfClass( X, Y ) <=> afficher( "true" ) ;;
(rule) querySuperClassOfClass( X, Y ) <=> afficher( "false" ) ;;
(rule) queryEquivalentClass( X ), owlEquivalentClass( X, Y ), logicalName( URIY, Y ) ==> ( !( X == Y ) ) | res( URIY ) ;;
(rule) querySubClassOfUri( URIC ), logicalName( URIC, X ) ==> ( querySubClassOf( X ), res( URIC ) ) ;;
(rule) r_querySubClassOf1 @ querySubClassOf( X ), owlSubclassOf( Y, X ), logicalName( URIY, Y ) ==> ( !( X == Y ) ) | ( querySubClassOf( Y ), queryEquivalentClass( X ), res( URIY ) ) ;;
(rule) r_querySubClassOfClassURI @ logicalName( URIX, X ), logicalName( URIY, Y ) \ querySubClassOfClassUri( URIX, URIY ) <=> querySubClassOfClass( X, Y ) ;;
(rule) owlSubclassOf( X, Y ) \ querySubClassOfClass( X, Y ) <=> afficher( "true" ) ;;
(rule) querySubClassOfClass( X, Y ) <=> afficher( "false" ) ;;
(rule) queryClassificationUri( URIX ), logicalName( URIX, X ) ==> queryClassification( X ) ;;
(rule) r_queryClassification1 @ queryClassification( X ), owlClassAssertion( X, C, true ), logicalName( URIC, C ) ==> ( res( URIC ), querySuperClassOf( C ), queryEquivalentClass( C ) ) ;;
(rule) rule1 @ logicalName( URIC, C ), logicalName( URIX, X ) \ queryInstanceURI( URIX, URIC ) <=> queryInstance( X, C ) ;;
(rule) rule2 @ owlClassAssertion( X, C, true ) \ queryInstance( X, C ) <=> afficher( "true" ) ;;
(rule) rule3 @ queryInstance( X, C ) <=> afficher( "false" ) ;;
(rule) resultRealisation( URIX, URIY ) ==> ( !prefixIntern( URIY ) ) | stockerRealisation( URIX, URIY ) ;;
(rule) realisation @ realisation(  ), owlClassAssertion( X, C, true ), logicalName( URIC, C ), logicalName( URIX, X ) ==> resultRealisation( URIX, URIC ) ;;
(rule) realisationPunning @ realisation(  ), owlClassAssertion( X, X, true ), logicalName( URI, X ) ==> resultRealisation( URI, URI ) ;;
(rule) owlEquivalentClass( X, Y ), logicalName( URIX, X ), logicalName( URIY, Y ) \ resultClassification( URIX, URIY ) <=> true ;;
(rule) resultClassification( URIX, URIY ) ==> ( ( !prefixIntern( URIY ) ) && ( !prefixIntern( URIX ) ) ) | stockerClassification( URIX, URIY ) ;;
(rule) classification(  ), owlSubclassOf( X, Y ), logicalName( URIX, X ), logicalName( URIY, Y ), logicalName( owlNothing, OwlNothingVar ) ==> ( !( URIX == owlNothing ) ) | resultClassification( URIX, URIY ) ;;
(rule) classification(  ), owlSubclassOf( X, X ), logicalName( URIX, X ) ==> resultClassification( URIX, URIX ) ;;
(rule) ResultVec( S, ID ) ==> afficherResultatSet( S, ID ) ;;
(rule) ResultVec( S, ID ) ==> stockerQueries( S, ID ) ;;
(rule) queryObjAssertionUri( URIP ) <=> queryObjAssertionWithId( URIP, get_next_id(  ) ) ;;
(rule) logicalName( URIP, P ) \ queryObjAssertionWithId( URIP, ID ) <=> queryObjAssertion( P, ID ) ;;
(rule) queryObjAssertionWithId( URIP, ID ) <=> success ;;
(rule) queryObjAssertion( P, ID ), owlObjectPropertyAssertion( X, P, Y ), logicalName( URIX, X ), logicalName( URIY, Y ) ==> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(rule) queryObjAssertion( P, ID ), owlObjectPropertyAssertion( X, P, X ), logicalName( URIX, X ) ==> ResultVec( makeVec( URIX, URIX ), ID ) ;;
(rule) queryObjAssertion( P, ID ) <=> success ;;
(rule) queryDataAssertionUri( URIP ) <=> queryDataAssertionWithId( URIP, get_next_id(  ) ) ;;
(rule) logicalName( URIP, P ) \ queryDataAssertionWithId( URIP, ID ) <=> queryDataAssertion( P, ID ) ;;
(rule) queryDataAssertionWithId( URIP, ID ) <=> success ;;
(rule) queryDataAssertion( P, ID ), owlDataPropertyAssertion( X, P, Y ), logicalName( URIX, X ) ==> ResultVec( makeVec( URIX, valueToString( Y ) ), ID ) ;;
(rule) queryDataAssertion( P, ID ) <=> success ;;
(rule) queryInstancesURI( URIC ) <=> queryInstancesWithId( URIC, get_next_id(  ) ) ;;
(rule) logicalName( URIC, C ) \ queryInstancesWithId( URIC, ID ) <=> queryInstances( C, ID ) ;;
(rule) queryInstancesWithId( URIC, ID ) <=> success ;;
(rule) queryInstances( C, ID ), owlClassAssertion( X, C, true ), logicalName( URIX, X ) ==> ResultVec( makeVec( URIX, emptyString ), ID ) ;;
(rule) queryInstances( C, ID ) <=> success ;;
(rule) queryObjAssertionSubjectUri( URIP, URIO ) <=> queryObjAssertionSubjectWithId( URIP, URIO, get_next_id(  ) ) ;;
(rule) logicalName( URIP, P ), logicalName( URIO, O ) \ queryObjAssertionSubjectWithId( URIP, URIO, ID ) <=> queryObjAssertionSubject( P, O, ID ) ;;
(rule) queryObjAssertionSubjectWithId( URIP, URIO, ID ) <=> success ;;
(rule) queryObjAssertionSubject( P, O, ID ), owlObjectPropertyAssertion( X, P, O ), logicalName( URIX, X ) ==> ResultVec( makeVec( URIX, emptyString ), ID ) ;;
(rule) queryObjAssertionSubject( P, O, ID ) <=> success ;;
(rule) querySubjectByObjectUri( URIP ) <=> querySubjectByObjectWithId( URIP, get_next_id(  ) ) ;;
(rule) logicalName( URIP, P ) \ querySubjectByObjectWithId( URIP, ID ) <=> querySubjectByObject( P, ID ) ;;
(rule) querySubjectByObjectWithId( URIP, ID ) <=> success ;;
(rule) querySubjectByObject( P, ID ), owlObjectPropertyAssertion( X, P, Y ), logicalName( URIX, X ), logicalName( URIY, Y ) ==> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(rule) querySubjectByObject( P, ID ) <=> success ;;
(rule) queryEngineeringStudentsUri( URIE, URIF, URIG, URIH, URIK ) <=> queryEngineeringStudentsWithId( URIE, URIF, URIG, URIH, URIK, get_next_id(  ) ) ;;
(rule) logicalName( URIE, E ), logicalName( URIF, F ), logicalName( URIG, G ), logicalName( URIH, H ), logicalName( URIK, K ) \ queryEngineeringStudentsWithId( URIE, URIF, URIG, URIH, URIK, ID ) <=> queryEngineeringStudents( E, F, G, H, K, ID ) ;;
(rule) queryEngineeringStudentsWithId( URIE, URIF, URIG, URIH, URIK, ID ) <=> success ;;
(rule) queryEngineeringStudents( E, F, G, H, K, ID ), owlClassAssertion( X, E, true ), owlObjectPropertyAssertion( X, F, Y ), owlObjectPropertyAssertion( Y, G, Z ), owlObjectPropertyAssertion( Z, H, K ), logicalName( URIX, X ), logicalName( URIY, Y ) ==> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(rule) queryEngineeringStudents( E, F, G, H, K, ID ) <=> success ;;
(rule) queryComplexStudentsUri( URIE, URIF, URIG, URIH, URIK ) <=> queryComplexStudentsWithId( URIE, URIF, URIG, URIH, URIK, get_next_id(  ) ) ;;
(rule) logicalName( URIE, E ), logicalName( URIF, F ), logicalName( URIG, G ), logicalName( URIH, H ), logicalName( URIK, K ) \ queryComplexStudentsWithId( URIE, URIF, URIG, URIH, URIK, ID ) <=> queryComplexStudents( E, F, G, H, K, ID ) ;;
(rule) queryComplexStudentsWithId( URIE, URIF, URIG, URIH, URIK, ID ) <=> success ;;
(rule) queryComplexStudents( E, F, G, H, K, ID ), owlClassAssertion( S, E, true ), owlClassAssertion( X, F, true ), owlObjectPropertyAssertion( X, G, Z ), owlObjectPropertyAssertion( Z, H, C ), owlObjectPropertyAssertion( S, K, C ), logicalName( URIS, S ), logicalName( URIC, C ) ==> ResultVec( makeVec( URIS, URIC ), ID ) ;;
(rule) queryComplexStudents( E, F, G, H, K, ID ) <=> success ;;
(occ rule) [-ResultVec( S, ID )#0][+ResultVec( S, ID )<idx#0>#passive] --> true ;;
(occ rule) [+ResultVec( S, ID )#1][] --> afficherResultatSet( S, ID ) ;;
(occ rule) [+ResultVec( S, ID )#2][] --> stockerQueries( S, ID ) ;;
(occ rule) [-classification(  )#0][+classification(  )#passive] --> true ;;
(occ rule) [+classification(  )#1][+logicalName( owlNothing, OwlNothingVar )<idx#0>#passive, +logicalName( URIX, X )#passive, ( !( URIX == owlNothing ) ), +logicalName( URIY, Y )#passive, +owlSubclassOf( X, Y )<idx#0>] --> resultClassification( URIX, URIY ) ;;
(occ rule) [+classification(  )#2][+owlSubclassOf( X, X ), +logicalName( URIX, X )<idx#1>#passive] --> resultClassification( URIX, URIX ) ;;
(occ rule) [-constructPropertyChain( PC, I, X, Y, N )#0][+constructPropertyChain( PC, I, X, Y, N )<idx#0>#passive] --> true ;;
(occ rule) chainStep @ [+constructPropertyChain( PC, I, X, Y, N )#1][( I < N ), +owlObjectPropertyChain( PC, P, J, N )<idx#0>, equalIncrement( J, I ), +owlObjectPropertyAssertion( Y, P, Z )<idx#0>] --> constructPropertyChain( PC, ( I + 1 ), X, Z, N ) ;;
(occ rule) finalChain @ [-constructPropertyChain( PC, N, X, Y, N )#2][] --> owlObjectPropertyAssertion( X, PC, Y ) ;;
(occ rule) [-intersectionSubclassCheck( X, C, I )#0][+intersectionSubclassCheck( X, C, I )<idx#0>#passive] --> true ;;
(occ rule) [-intersectionSubclassCheck( C, A, I )#1][+intersectionSubclassCheck( C, A, I )<idx#0>#passive] --> true ;;
(occ rule) r8b @ [+intersectionSubclassCheck( C, A, I )#2][( I > 0 ), +owlIntersectionClass( C, V, I )<idx#0>, +owlSubclassOf( A, V )<idx#0>] --> intersectionSubclassCheck( C, A, ( I + 1 ) ) ;;
(occ rule) r8c @ [-intersectionSubclassCheck( C, A, N )#3][+owlIntersectionOfLoop( C, ITEND, ITEND, N )<idx#0>] --> owlSubclassOf( A, C ) ;;
(occ rule) [-logicalName( URI, X )#0][+logicalName( URI, X )<idx#2>#passive] --> true ;;
(occ rule) [+logicalName( URIC, C )#1][( !( URIC == "http://www.w3.org/2002/07/owl#Thing" ) ), +logicalName( owlThing, OwlThingVar )<idx#0>#passive, +owlClass( C )<idx#0>] --> owlSubclassOf( C, OwlThingVar ) ;;
(occ rule) [+logicalName( URIC, C )#2][( !( URIC == owlNothing ) ), +logicalName( owlNothing, OwlNothingVar )<idx#0>#passive, +owlClass( C )<idx#0>] --> owlSubclassOf( OwlNothingVar, C ) ;;
(occ rule) [-logicalName( emptyString, V )#3][-owlClassAssertion( V, Y, true )<idx#0>, +owlClassAssertion( W, Y, true )<idx#1>, +owlObjectPropertyAssertion( U, P, W )<idx#1>, -owlObjectPropertyAssertion( U, P, V )<idx#2>, +logicalName( URI, W )<idx#1>#passive, ( !( URI == emptyString ) )] --> success ;;
(occ rule) [+logicalName( URIX, X )#6][+owlDataPropertyAssertion( X, P, Y )<idx#0>, +queryDataAssertion( P, ID )<idx#0>] --> ResultVec( makeVec( URIX, valueToString( Y ) ), ID ) ;;
(occ rule) [-owlAsymmetricObjectProperty( P )#0][+owlAsymmetricObjectProperty( P )<idx#0>#passive] --> true ;;
(occ rule) AsymmetricProperty1 @ [+owlAsymmetricObjectProperty( P )#1][+owlObjectPropertyAssertion( X, P, Y )<idx#3>] --> owlNegativeObjectAssertion( Y, P, X ) ;;
(occ rule) [-owlCandidatsIntersection( X, C, I )#0][+owlCandidatsIntersection( X, C, I )<idx#0>#passive] --> true ;;
(occ rule) r3 @ [+owlCandidatsIntersection( X, C, I )#1][+owlClassAssertion( X, V, true )<idx#0>, +owlIntersectionClass( C, V, I )<idx#1>] --> owlCandidatsIntersection( X, C, ( I + 1 ) ) ;;
(occ rule) r5 @ [+owlCandidatsIntersection( X, C, I )#2][+owlIntersectionOfLoop( C, ITEND, ITEND, I )<idx#0>] --> owlClassAssertion( X, C, true ) ;;
(occ rule) [-owlClass( C )#0][+owlClass( C )<idx#0>#passive] --> true ;;
(occ rule) [+owlClass( C )#1][] --> owlEquivalentClass( C, C ) ;;
(occ rule) [+owlClass( C )#2][+logicalName( owlThing, OwlThingVar )<idx#0>#passive, +logicalName( URIC, C )<idx#1>, ( !( URIC == "http://www.w3.org/2002/07/owl#Thing" ) )] --> owlSubclassOf( C, OwlThingVar ) ;;
(occ rule) [+owlClass( C )#3][+logicalName( owlNothing, OwlNothingVar )<idx#0>#passive, +logicalName( URIC, C )<idx#1>, ( !( URIC == owlNothing ) )] --> owlSubclassOf( OwlNothingVar, C ) ;;
(occ rule) [-owlClassAssertion( X, A, B )#0][+owlClassAssertion( X, A, B )<idx#2>#passive] --> true ;;
(occ rule) DisjointClass @ [-owlClassAssertion( X, A, true )#1][-owlClassAssertion( X, B, true )<idx#0>, -owlDisjointClass( A, B )<idx#0>] --> failure ;;
(occ rule) DisjointClass @ [-owlClassAssertion( X, B, true )#2][-owlClassAssertion( X, A, true )<idx#0>, -owlDisjointClass( A, B )<idx#0>] --> failure ;;
(occ rule) complementOf @ [-owlClassAssertion( X, A, true )#3][-owlClassAssertion( X, NOTA, true )<idx#0>, -owlComplementOf( A, NOTA )<idx#0>] --> failure ;;
(occ rule) complementOf @ [-owlClassAssertion( X, NOTA, true )#4][-owlClassAssertion( X, A, true )<idx#0>, -owlComplementOf( A, NOTA )<idx#0>] --> failure ;;
(occ rule) [+owlClassAssertion( X, C, true )#5][] --> ( owlClass( C ), owlNamedIndividual( X ) ) ;;
(occ rule) subclass @ [+owlClassAssertion( X, A, true )#6][+owlSubclassOf( A, B )<idx#1>, ( !( A == B ) )] --> owlClassAssertion( X, B, true ) ;;
(occ rule) equivalentClass @ [+owlClassAssertion( X, A, true )#7][+owlEquivalentClass( A, B )<idx#0>, ( !( A == B ) )] --> owlClassAssertion( X, B, true ) ;;
(occ rule) sameIndividual6 @ [+owlClassAssertion( X, C, B )#8][+owlSameIndividual( X, Y )<idx#0>, ( !( X == Y ) )] --> owlClassAssertion( Y, C, B ) ;;
(occ rule) [+owlClassAssertion( X, V, true )#9][-owlUnionClass( C, V )<idx#0>] --> owlClassAssertion( X, C, true ) ;;
(occ rule) r2 @ [+owlClassAssertion( X, V, true )#10][+owlIntersectionClass( C, V, 0 )<idx#2>] --> owlCandidatsIntersection( X, C, 0 ) ;;
(occ rule) r3 @ [+owlClassAssertion( X, V, true )#11][+owlIntersectionClass( C, V, I )<idx#3>, +owlCandidatsIntersection( X, C, I )<idx#0>] --> owlCandidatsIntersection( X, C, ( I + 1 ) ) ;;
(occ rule) r6 @ [+owlClassAssertion( X, C, true )#12][+owlIntersectionClass( C, C1, _ )<idx#4>] --> owlClassAssertion( X, C1, true ) ;;
(occ rule) [-owlClassAssertion( X, NOTA, false )#13][+owlClassAssertion( X, NOTA, true )<idx#2>] --> true ;;
(occ rule) [+owlClassAssertion( X, NOTA, true )#14][-owlClassAssertion( X, NOTA, false )<idx#2>] --> true ;;
(occ rule) [-owlClassAssertion( X, NOTA, false )#15][+owlClassAssertion( X, A, true )<idx#0>, +owlComplementOf( A, NOTA )<idx#0>] --> true ;;
(occ rule) [+owlClassAssertion( X, A, true )#16][-owlClassAssertion( X, NOTA, false )<idx#0>, +owlComplementOf( A, NOTA )<idx#0>] --> true ;;
(occ rule) [+owlClassAssertion( V, Y, true )#17][+owlObjectSomeValuesFrom( C, P, Y )<idx#0>, +owlObjectPropertyAssertion( U, P, V )<idx#4>] --> owlClassAssertion( U, C, true ) ;;
(occ rule) [+owlClassAssertion( U, C, true )#18][+owlObjectSomeValuesFrom( C, P, Y )<idx#1>] --> ( owlObjectPropertyAssertion( U, P, V ), logicalName( emptyString, V ), owlClassAssertion( V, Y, true ) ) ;;
(occ rule) [-owlClassAssertion( V, Y, true )#19][-logicalName( emptyString, V )<idx#2>, +owlClassAssertion( W, Y, true )<idx#1>, +owlObjectPropertyAssertion( U, P, W )<idx#1>, -owlObjectPropertyAssertion( U, P, V )<idx#2>, +logicalName( URI, W )<idx#1>#passive, ( !( URI == emptyString ) )] --> success ;;
(occ rule) [+owlClassAssertion( W, Y, true )#20][-owlClassAssertion( V, Y, true )<idx#1>, -logicalName( emptyString, V )<idx#2>, -owlObjectPropertyAssertion( U, P, V )<idx#1>, +owlObjectPropertyAssertion( U, P, W )<idx#2>, +logicalName( URI, W )<idx#1>#passive, ( !( URI == emptyString ) )] --> success ;;
(occ rule) [+owlClassAssertion( U, C, true )#21][+owlDataSomeValuesFrom( C, P, DR )<idx#0>] --> ( owlDataPropertyAssertion( U, P, createValue( emptyString, DR ) ), logicalName( emptyString, V ) ) ;;
(occ rule) [-owlClassAssertion( U, C, true )#22][-owlObjectMaxCardinality( C, P, 0 )<idx#0>, -owlObjectPropertyAssertion( U, P, _ )<idx#0>] --> failure ;;
(occ rule) [-owlClassAssertion( U, C, true )#23][-owlObjectMaxCardinality( C, P, 1 )<idx#0>, -owlObjectPropertyAssertion( U, P, Y1 )<idx#0>, -owlObjectPropertyAssertion( U, P, Y2 )<idx#0>, ( !( Y1 == Y2 ) )] --> owlSameIndividual( Y1, Y2 ) ;;
(occ rule) [-owlClassAssertion( U, C, true )#24][-owlDataMaxCardinality( C, P, 0 )<idx#0>, -owlDataPropertyAssertion( U, P, _ )<idx#1>] --> failure ;;
(occ rule) [-owlClassAssertion( U, C, true )#25][-owlDataMaxCardinality( C, P, 1 )<idx#0>, -owlDataPropertyAssertion( U, P, Y1 )<idx#1>, -owlDataPropertyAssertion( U, P, Y2 )<idx#1>, ( !( Y1 == Y2 ) )] --> failure ;;
(occ rule) [+owlClassAssertion( U, C, true )#26][+owlHasValueObject( C, P, Y )<idx#0>, +owlObjectProperty( P )<idx#0>] --> owlObjectPropertyAssertion( U, P, Y ) ;;
(occ rule) hasValueSubsumption @ [+owlClassAssertion( A, Y, true )#27][+owlHasValueObject( C, P, A )<idx#1>, +owlObjectSomeValuesFrom( SV, P, Y )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionClass @ [+owlClassAssertion( A, Y1, true )#28][+owlHasValueObject( C, P, A )<idx#1>, +owlSubclassOf( Y1, Y2 )<idx#1>, +owlObjectSomeValuesFrom( SV, P, Y2 )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionProp @ [+owlClassAssertion( A, Y, true )#29][+owlHasValueObject( C, P1, A )<idx#1>, +owlSubObjectPropertyOf( P1, P2 )<idx#0>, +owlObjectSomeValuesFrom( SV, P2, Y )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionPropClass @ [+owlClassAssertion( A, Y1, true )#30][+owlHasValueObject( C, P1, A )<idx#1>, +owlSubObjectPropertyOf( P1, P2 )<idx#0>, +owlSubclassOf( Y1, Y2 )<idx#1>, +owlObjectSomeValuesFrom( SV, P2, Y2 )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) [+owlClassAssertion( X, C, true )#31][+owlHasKey( C, P, 0, N )<idx#0>, +owlClassAssertion( Y, C, true )<idx#1>, ( !( X == Y ) )] --> owlHasKeyCheck( C, X, Y, 0, N ) ;;
(occ rule) [+owlClassAssertion( Y, C, true )#32][+owlHasKey( C, P, 0, N )<idx#0>, +owlClassAssertion( X, C, true )<idx#1>, ( !( X == Y ) )] --> owlHasKeyCheck( C, X, Y, 0, N ) ;;
(occ rule) r_queryClassification1 @ [+owlClassAssertion( X, C, true )#33][+queryClassification( X )<idx#0>, +logicalName( URIC, C )<idx#1>#passive] --> ( res( URIC ), querySuperClassOf( C ), queryEquivalentClass( C ) ) ;;
(occ rule) realisation @ [+owlClassAssertion( X, C, true )#35][+logicalName( URIC, C )<idx#1>#passive, +logicalName( URIX, X )<idx#1>#passive, +realisation(  )] --> resultRealisation( URIX, URIC ) ;;
(occ rule) realisationPunning @ [+owlClassAssertion( X, X, true )#36][+logicalName( URI, X )<idx#1>#passive, +realisation(  )] --> resultRealisation( URI, URI ) ;;
(occ rule) [+owlClassAssertion( X, C, true )#37][+queryInstances( C, ID )<idx#0>, +logicalName( URIX, X )<idx#1>#passive] --> ResultVec( makeVec( URIX, emptyString ), ID ) ;;
(occ rule) [+owlClassAssertion( X, E, true )#38][+queryEngineeringStudents( E, F, G, H, K, ID )<idx#0>, +owlObjectPropertyAssertion( X, F, Y )<idx#0>, +owlObjectPropertyAssertion( Y, G, Z )<idx#0>, +owlObjectPropertyAssertion( Z, H, K )<idx#2>, +logicalName( URIX, X )<idx#1>#passive, +logicalName( URIY, Y )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(occ rule) [+owlClassAssertion( S, E, true )#39][+owlClassAssertion( X, F, true )<idx#3>, +queryComplexStudents( E, F, G, H, K, ID )<idx#0>, +owlObjectPropertyAssertion( X, G, Z )<idx#0>, +owlObjectPropertyAssertion( Z, H, C )<idx#0>, +owlObjectPropertyAssertion( S, K, C )<idx#2>, +logicalName( URIS, S )<idx#1>#passive, +logicalName( URIC, C )<idx#1>#passive] --> ResultVec( makeVec( URIS, URIC ), ID ) ;;
(occ rule) [+owlClassAssertion( X, F, true )#40][+owlClassAssertion( S, E, true )<idx#3>, +queryComplexStudents( E, F, G, H, K, ID )<idx#0>, +owlObjectPropertyAssertion( X, G, Z )<idx#0>, +owlObjectPropertyAssertion( Z, H, C )<idx#0>, +owlObjectPropertyAssertion( S, K, C )<idx#2>, +logicalName( URIS, S )<idx#1>#passive, +logicalName( URIC, C )<idx#1>#passive] --> ResultVec( makeVec( URIS, URIC ), ID ) ;;
(occ rule) [-owlComplementOf( A, NOTA )#0][+owlComplementOf( A, NOTA )<idx#0>#passive] --> true ;;
(occ rule) complementOf @ [-owlComplementOf( A, NOTA )#1][-owlClassAssertion( X, A, true )<idx#1>, -owlClassAssertion( X, NOTA, true )<idx#2>] --> failure ;;
(occ rule) [+owlComplementOf( A, NOTA )#2][+owlNamedIndividual( X )] --> owlClassAssertion( X, NOTA, false ) ;;
(occ rule) [+owlComplementOf( A, NOTA )#3][-owlClassAssertion( X, NOTA, false )<idx#1>, +owlClassAssertion( X, A, true )<idx#2>] --> true ;;
(occ rule) [-owlDataAllValuesFrom( C, P, DR )#0][+owlDataAllValuesFrom( C, P, DR )<idx#0>#passive] --> true ;;
(occ rule) [-owlDataMaxCardinality( C, P, N )#0][+owlDataMaxCardinality( C, P, N )<idx#1>#passive] --> true ;;
(occ rule) [-owlDataMaxCardinality( C, P, 0 )#1][-owlClassAssertion( U, C, true )<idx#1>, -owlDataPropertyAssertion( U, P, _ )<idx#1>] --> failure ;;
(occ rule) [-owlDataMaxCardinality( C, P, 1 )#2][-owlClassAssertion( U, C, true )<idx#1>, -owlDataPropertyAssertion( U, P, Y1 )<idx#1>, -owlDataPropertyAssertion( U, P, Y2 )<idx#1>, ( !( Y1 == Y2 ) )] --> failure ;;
(occ rule) [-owlDataProperty( P )#0][+owlDataProperty( P )<idx#0>#passive] --> true ;;
(occ rule) [+owlDataProperty( P )#1][] --> ( owlEquivalentDataProperty( P, P ), owlSubDataPropertyOf( P, P ) ) ;;
(occ rule) [-owlDataPropertyAssertion( X, P, Y )#0][+owlDataPropertyAssertion( X, P, Y )<idx#2>#passive] --> true ;;
(occ rule) DisjointDataProperty @ [-owlDataPropertyAssertion( X, A, Y )#1][-owlDataPropertyAssertion( X, B, Y )<idx#3>, -owlDisjointDataProperty( A, B )<idx#0>] --> failure ;;
(occ rule) DisjointDataProperty @ [-owlDataPropertyAssertion( X, B, Y )#2][-owlDataPropertyAssertion( X, A, Y )<idx#3>, -owlDisjointDataProperty( A, B )<idx#0>] --> failure ;;
(occ rule) NegativeDataAssertion @ [-owlDataPropertyAssertion( X, P, Y )#3][-owlNegativeDataAssertion( X, P, Y )<idx#0>] --> failure ;;
(occ rule) DataPropertyDomain @ [+owlDataPropertyAssertion( X, P, _ )#4][+owlDataPropertyDomain( P, DP )<idx#0>] --> owlClassAssertion( X, DP, true ) ;;
(occ rule) DataPropertyRange @ [-owlDataPropertyAssertion( _, P, Y )#5][-owlDataPropertyRange( P, DR )<idx#0>, invalidType( DR, Y )] --> failure ;;
(occ rule) subDataProperty @ [+owlDataPropertyAssertion( X, P2, Y )#6][+owlSubDataPropertyOf( P2, P1 )<idx#0>, ( !( P2 == P1 ) )] --> owlDataPropertyAssertion( X, P1, Y ) ;;
(occ rule) sameIndividual4 @ [+owlDataPropertyAssertion( X, P, O )#7][+owlSameIndividual( X, Y )<idx#0>, ( !( X == Y ) )] --> owlDataPropertyAssertion( Y, P, O ) ;;
(occ rule) functionalDataProperty @ [-owlDataPropertyAssertion( X, P, Y )#8][-owlDataPropertyAssertion( X, P, Z )<idx#1>, ( !( Y == Z ) ), -owlFunctionalDataProperty( P )<idx#0>] --> failure ;;
(occ rule) functionalDataProperty @ [-owlDataPropertyAssertion( X, P, Z )#9][-owlDataPropertyAssertion( X, P, Y )<idx#1>, ( !( Y == Z ) ), -owlFunctionalDataProperty( P )<idx#0>] --> failure ;;
(occ rule) [+owlDataPropertyAssertion( X, P, Y )#10][] --> owlDataValue( Y, ( ( *Y ) . val ), ( ( *Y ) . typeVal ) ) ;;
(occ rule) [+owlDataPropertyAssertion( U, P, V )#11][+owlDataSomeValuesFrom( C, P, DR )<idx#1>, ( !invalidType( DR, V ) )] --> owlClassAssertion( U, C, true ) ;;
(occ rule) [-owlDataPropertyAssertion( U, P, V )#12][-owlDataValue( V, emptyString, TypeV )<idx#0>, +owlDataPropertyAssertion( U, P, W )<idx#1>, +owlDataValue( W, ValW, TypeW )<idx#1>, sameDataType( TypeV, TypeW ), ( !( ValW == emptyString ) )] --> success ;;
(occ rule) [+owlDataPropertyAssertion( U, P, W )#13][-owlDataValue( V, emptyString, TypeV )<idx#2>, -owlDataPropertyAssertion( U, P, V )<idx#2>, +owlDataValue( W, ValW, TypeW )<idx#1>, sameDataType( TypeV, TypeW ), ( !( ValW == emptyString ) )] --> success ;;
(occ rule) [-owlDataPropertyAssertion( U, P, _ )#14][-owlDataMaxCardinality( C, P, 0 )<idx#2>, -owlClassAssertion( U, C, true )<idx#2>] --> failure ;;
(occ rule) [-owlDataPropertyAssertion( U, P, Y1 )#15][-owlDataMaxCardinality( C, P, 1 )<idx#2>, -owlClassAssertion( U, C, true )<idx#2>, -owlDataPropertyAssertion( U, P, Y2 )<idx#1>, ( !( Y1 == Y2 ) )] --> failure ;;
(occ rule) [-owlDataPropertyAssertion( U, P, Y2 )#16][-owlDataMaxCardinality( C, P, 1 )<idx#2>, -owlClassAssertion( U, C, true )<idx#2>, -owlDataPropertyAssertion( U, P, Y1 )<idx#1>, ( !( Y1 == Y2 ) )] --> failure ;;
(occ rule) [+owlDataPropertyAssertion( X, P, V )#17][+owlDataPropertyAssertion( Y, P, V )<idx#4>, -owlHasKeyCheck( C, X, Y, I, N )<idx#0>, +owlHasKey( C, P, I, N )<idx#1>] --> owlHasKeyCheck( C, X, Y, ( I + 1 ), N ) ;;
(occ rule) [+owlDataPropertyAssertion( Y, P, V )#18][+owlDataPropertyAssertion( X, P, V )<idx#4>, -owlHasKeyCheck( C, X, Y, I, N )<idx#0>, +owlHasKey( C, P, I, N )<idx#1>] --> owlHasKeyCheck( C, X, Y, ( I + 1 ), N ) ;;
(occ rule) [+owlDataPropertyAssertion( X, P, Y )#19][+queryDataAssertion( P, ID )<idx#0>, +logicalName( URIX, X )<idx#1>] --> ResultVec( makeVec( URIX, valueToString( Y ) ), ID ) ;;
(occ rule) [-owlDataPropertyDomain( P, C )#0][+owlDataPropertyDomain( P, C )<idx#1>#passive] --> true ;;
(occ rule) [+owlDataPropertyDomain( P2, C )#1][+owlSubDataPropertyOf( P1, P2 )<idx#1>, ( !( P1 == P2 ) )] --> owlDataPropertyDomain( P1, C ) ;;
(occ rule) DataPropertyDomain @ [+owlDataPropertyDomain( P, DP )#2][+owlDataPropertyAssertion( X, P, _ )<idx#5>] --> owlClassAssertion( X, DP, true ) ;;
(occ rule) [-owlDataPropertyRange( P, R )#0][+owlDataPropertyRange( P, R )<idx#1>#passive] --> true ;;
(occ rule) [+owlDataPropertyRange( P2, C )#1][+owlSubDataPropertyOf( P1, P2 )<idx#1>, ( !( P1 == P2 ) )] --> owlDataPropertyRange( P1, C ) ;;
(occ rule) DataPropertyRange @ [-owlDataPropertyRange( P, DR )#2][-owlDataPropertyAssertion( _, P, Y )<idx#5>, invalidType( DR, Y )] --> failure ;;
(occ rule) [-owlDataSomeValuesFrom( C, P, DR )#0][+owlDataSomeValuesFrom( C, P, DR )<idx#2>#passive] --> true ;;
(occ rule) [+owlDataSomeValuesFrom( C, P, DR )#1][+owlDataPropertyAssertion( U, P, V )<idx#5>, ( !invalidType( DR, V ) )] --> owlClassAssertion( U, C, true ) ;;
(occ rule) [+owlDataSomeValuesFrom( C, P, DR )#2][+owlClassAssertion( U, C, true )<idx#1>] --> ( owlDataPropertyAssertion( U, P, createValue( emptyString, DR ) ), logicalName( emptyString, V ) ) ;;
(occ rule) [-owlDataValue( V, S, T )#0][+owlDataValue( V, S, T )<idx#3>#passive] --> true ;;
(occ rule) [-owlDataValue( V, emptyString, TypeV )#1][-owlDataPropertyAssertion( U, P, V )<idx#6>, +owlDataPropertyAssertion( U, P, W )<idx#1>, +owlDataValue( W, ValW, TypeW )<idx#1>, sameDataType( TypeV, TypeW ), ( !( ValW == emptyString ) )] --> success ;;
(occ rule) [+owlDataValue( W, ValW, TypeW )#2][( !( ValW == emptyString ) ), -owlDataValue( V, emptyString, TypeV )<idx#2>, sameDataType( TypeV, TypeW ), -owlDataPropertyAssertion( U, P, V )<idx#6>, +owlDataPropertyAssertion( U, P, W )<idx#2>] --> success ;;
(occ rule) [-owlDifferentIndividual( X, Y )#0][+owlDifferentIndividual( X, Y )<idx#0>#passive] --> true ;;
(occ rule) DifferentIndividual @ [-owlDifferentIndividual( X, Y )#1][-owlSameIndividual( X, Y )<idx#1>] --> failure ;;
(occ rule) [-owlDisjointClass( A, B )#0][+owlDisjointClass( A, B )<idx#0>#passive] --> true ;;
(occ rule) DisjointClass @ [-owlDisjointClass( A, B )#1][-owlClassAssertion( X, A, true )<idx#1>, -owlClassAssertion( X, B, true )<idx#2>] --> failure ;;
(occ rule) [-owlDisjointDataProperty( A, B )#0][+owlDisjointDataProperty( A, B )<idx#0>#passive] --> true ;;
(occ rule) DisjointDataProperty @ [-owlDisjointDataProperty( A, B )#1][-owlDataPropertyAssertion( X, A, Y )<idx#5>, -owlDataPropertyAssertion( X, B, Y )<idx#2>] --> failure ;;
(occ rule) [-owlDisjointObjectProperty( A, B )#0][+owlDisjointObjectProperty( A, B )<idx#0>#passive] --> true ;;
(occ rule) DisjointObjProperty @ [-owlDisjointObjectProperty( A, B )#1][-owlObjectPropertyAssertion( X, A, Y )<idx#3>, -owlObjectPropertyAssertion( X, B, Y )<idx#2>] --> failure ;;
(occ rule) [-owlEquivalentClass( A, B )#0][+owlEquivalentClass( A, B )<idx#1>#passive] --> true ;;
(occ rule) equivalentClass @ [+owlEquivalentClass( A, B )#1][( !( A == B ) ), +owlClassAssertion( X, A, true )<idx#1>] --> owlClassAssertion( X, B, true ) ;;
(occ rule) [+owlEquivalentClass( A, B )#2][( !( A == B ) )] --> ( owlSubclassOf( A, B ), owlSubclassOf( B, A ) ) ;;
(occ rule) [+owlEquivalentClass( X, Y )#3][( !( X == Y ) ), +queryEquivalentClass( X )<idx#0>, +logicalName( URIY, Y )<idx#1>#passive] --> res( URIY ) ;;
(occ rule) [+owlEquivalentClass( X, Y )#4][+logicalName( URIX, X )<idx#1>#passive, -resultClassification( URIX, URIY )<idx#0>, +logicalName( URIY, Y )<idx#2>#passive] --> true ;;
(occ rule) [-owlEquivalentDataProperty( A, B )#0][+owlEquivalentDataProperty( A, B )<idx#0>#passive] --> true ;;
(occ rule) [+owlEquivalentDataProperty( A, B )#1][( !( A == B ) )] --> ( owlSubDataPropertyOf( A, B ), owlSubDataPropertyOf( B, A ) ) ;;
(occ rule) [-owlEquivalentObjectProperty( A, B )#0][+owlEquivalentObjectProperty( A, B )<idx#0>#passive] --> true ;;
(occ rule) [+owlEquivalentObjectProperty( A, B )#1][( !( A == B ) )] --> ( owlSubObjectPropertyOf( A, B ), owlSubObjectPropertyOf( B, A ) ) ;;
(occ rule) [-owlFunctionalDataProperty( P )#0][+owlFunctionalDataProperty( P )<idx#0>#passive] --> true ;;
(occ rule) functionalDataProperty @ [-owlFunctionalDataProperty( P )#1][-owlDataPropertyAssertion( X, P, Y )<idx#5>, -owlDataPropertyAssertion( X, P, Z )<idx#1>, ( !( Y == Z ) )] --> failure ;;
(occ rule) [-owlFunctionalObjectProperty( P )#0][+owlFunctionalObjectProperty( P )<idx#0>#passive] --> true ;;
(occ rule) functionalObjProperty @ [+owlFunctionalObjectProperty( P )#1][+owlObjectPropertyAssertion( X, P, Y )<idx#3>, +owlObjectPropertyAssertion( X, P, Z )<idx#0>, ( !( Y == Z ) )] --> owlSameIndividual( Y, Z ) ;;
(occ rule) [-owlHasKey( C, P, I, N )#0][+owlHasKey( C, P, I, N )<idx#1>#passive] --> true ;;
(occ rule) [+owlHasKey( C, P, 0, N )#1][+owlClassAssertion( X, C, true )<idx#1>, +owlClassAssertion( Y, C, true )<idx#1>, ( !( X == Y ) )] --> owlHasKeyCheck( C, X, Y, 0, N ) ;;
(occ rule) [+owlHasKey( C, P, I, N )#2][-owlHasKeyCheck( C, X, Y, I, N )<idx#1>, +owlObjectPropertyAssertion( X, P, V )<idx#0>, +owlObjectPropertyAssertion( Y, P, V )<idx#2>] --> owlHasKeyCheck( C, X, Y, ( I + 1 ), N ) ;;
(occ rule) [+owlHasKey( C, P, I, N )#3][-owlHasKeyCheck( C, X, Y, I, N )<idx#1>, +owlDataPropertyAssertion( X, P, V )<idx#1>, +owlDataPropertyAssertion( Y, P, V )<idx#2>] --> owlHasKeyCheck( C, X, Y, ( I + 1 ), N ) ;;
(occ rule) [-owlHasKeyCheck( C, X, Y, I, N )#0][+owlHasKeyCheck( C, X, Y, I, N )<idx#2>#passive] --> true ;;
(occ rule) [-owlHasKeyCheck( C, X, Y, I, N )#1][+owlHasKey( C, P, I, N )<idx#2>, +owlObjectPropertyAssertion( Y, P, V )<idx#0>, +owlObjectPropertyAssertion( X, P, V )<idx#2>] --> owlHasKeyCheck( C, X, Y, ( I + 1 ), N ) ;;
(occ rule) [-owlHasKeyCheck( C, X, Y, I, N )#2][+owlHasKey( C, P, I, N )<idx#2>, +owlDataPropertyAssertion( Y, P, V )<idx#1>, +owlDataPropertyAssertion( X, P, V )<idx#2>] --> owlHasKeyCheck( C, X, Y, ( I + 1 ), N ) ;;
(occ rule) [-owlHasKeyCheck( C, X, Y, N, N )#3][] --> owlSameIndividual( X, Y ) ;;
(occ rule) [-owlHasValueObject( C, P, Y )#0][+owlHasValueObject( C, P, Y )<idx#2>#passive] --> true ;;
(occ rule) [+owlHasValueObject( C, P, Y )#1][+owlClassAssertion( U, C, true )<idx#1>, +owlObjectProperty( P )<idx#0>] --> owlObjectPropertyAssertion( U, P, Y ) ;;
(occ rule) [+owlHasValueObject( C, P, Y )#2][+owlObjectPropertyAssertion( U, P, Y )<idx#4>] --> owlClassAssertion( U, C, true ) ;;
(occ rule) hasValueSubsumption @ [+owlHasValueObject( C, P, A )#3][+owlClassAssertion( A, Y, true )<idx#0>, +owlObjectSomeValuesFrom( SV, P, Y )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionClass @ [+owlHasValueObject( C, P, A )#4][+owlClassAssertion( A, Y1, true )<idx#0>, +owlSubclassOf( Y1, Y2 )<idx#1>, +owlObjectSomeValuesFrom( SV, P, Y2 )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionProp @ [+owlHasValueObject( C, P1, A )#5][+owlClassAssertion( A, Y, true )<idx#0>, +owlSubObjectPropertyOf( P1, P2 )<idx#0>, +owlObjectSomeValuesFrom( SV, P2, Y )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionPropClass @ [+owlHasValueObject( C, P1, A )#6][+owlClassAssertion( A, Y1, true )<idx#0>, +owlSubObjectPropertyOf( P1, P2 )<idx#0>, +owlSubclassOf( Y1, Y2 )<idx#1>, +owlObjectSomeValuesFrom( SV, P2, Y2 )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) [-owlIntersectionClass( C, V, I )#0][+owlIntersectionClass( C, V, I )<idx#1>#passive] --> true ;;
(occ rule) r2 @ [+owlIntersectionClass( C, V, 0 )#1][+owlClassAssertion( X, V, true )<idx#1>] --> owlCandidatsIntersection( X, C, 0 ) ;;
(occ rule) r3 @ [+owlIntersectionClass( C, V, I )#2][+owlClassAssertion( X, V, true )<idx#1>, +owlCandidatsIntersection( X, C, I )<idx#0>] --> owlCandidatsIntersection( X, C, ( I + 1 ) ) ;;
(occ rule) r6 @ [+owlIntersectionClass( C, C1, _ )#3][+owlClassAssertion( X, C, true )<idx#1>] --> owlClassAssertion( X, C1, true ) ;;
(occ rule) r7 @ [+owlIntersectionClass( C1, Component, _ )#4][+owlSubclassOf( C2, C1 )<idx#2>, ( !( C1 == C2 ) )] --> owlSubclassOf( C2, Component ) ;;
(occ rule) r8a @ [+owlIntersectionClass( C, V, 0 )#5][+owlSubclassOf( A, V )<idx#2>] --> intersectionSubclassCheck( C, A, 1 ) ;;
(occ rule) r8b @ [+owlIntersectionClass( C, V, I )#6][( I > 0 ), +intersectionSubclassCheck( C, A, I )<idx#1>, +owlSubclassOf( A, V )<idx#0>] --> intersectionSubclassCheck( C, A, ( I + 1 ) ) ;;
(occ rule) [-owlIntersectionOf( C, S )#0][+owlIntersectionOf( C, S )<idx#0>#passive] --> true ;;
(occ rule) r0 @ [+owlIntersectionOf( C, S )#1][] --> owlIntersectionOfLoop( C, ( ( *S ) . begin(  ) ), ( ( *S ) . end(  ) ), 0 ) ;;
(occ rule) [-owlIntersectionOfLoop( C, IT, ITEND, I )#0][+owlIntersectionOfLoop( C, IT, ITEND, I )<idx#1>#passive] --> true ;;
(occ rule) r1 @ [-owlIntersectionOfLoop( C, IT, ITEND, I )#1][( !( IT == ITEND ) )] --> ( owlIntersectionClass( C, ( *( *IT ) ), I ), owlIntersectionOfLoop( C, ( std :: next( ( *IT ) ) ), ITEND, ( I + 1 ) ) ) ;;
(occ rule) r5 @ [+owlIntersectionOfLoop( C, ITEND, ITEND, I )#2][+owlCandidatsIntersection( X, C, I )<idx#1>] --> owlClassAssertion( X, C, true ) ;;
(occ rule) r8c @ [+owlIntersectionOfLoop( C, ITEND, ITEND, N )#3][-intersectionSubclassCheck( C, A, N )<idx#1>] --> owlSubclassOf( A, C ) ;;
(occ rule) [-owlInverseFunctionalObjectProperty( P )#0][+owlInverseFunctionalObjectProperty( P )<idx#0>#passive] --> true ;;
(occ rule) inverseFunctional @ [+owlInverseFunctionalObjectProperty( P )#1][+owlObjectPropertyAssertion( X, P, Z )<idx#3>, +owlObjectPropertyAssertion( Y, P, Z )<idx#4>, ( !( X == Y ) )] --> owlSameIndividual( X, Y ) ;;
(occ rule) [-owlInverseObjectProperty( P1, P2 )#0][+owlInverseObjectProperty( P1, P2 )<idx#0>#passive] --> true ;;
(occ rule) inverseProperty @ [+owlInverseObjectProperty( P1, P2 )#1][+owlObjectPropertyAssertion( X, P1, Y )<idx#3>] --> owlObjectPropertyAssertion( Y, P2, X ) ;;
(occ rule) [+owlInverseObjectProperty( P1, P2 )#2][] --> owlInverseObjectProperty( P2, P1 ) ;;
(occ rule) [-owlIrreflexiveObjectProperty( P )#0][+owlIrreflexiveObjectProperty( P )<idx#0>#passive] --> true ;;
(occ rule) irreflexiveProperty @ [-owlIrreflexiveObjectProperty( P )#1][-owlObjectPropertyAssertion( X, P, X )<idx#3>] --> failure ;;
(occ rule) [-owlNamedIndividual( C )#0][+owlNamedIndividual( C )<idx#0>#passive] --> true ;;
(occ rule) [+owlNamedIndividual( X )#1][+owlComplementOf( A, NOTA )] --> owlClassAssertion( X, NOTA, false ) ;;
(occ rule) [-owlNegativeDataAssertion( X, P, Y )#0][+owlNegativeDataAssertion( X, P, Y )<idx#0>#passive] --> true ;;
(occ rule) NegativeDataAssertion @ [-owlNegativeDataAssertion( X, P, Y )#1][-owlDataPropertyAssertion( X, P, Y )<idx#2>] --> failure ;;
(occ rule) [-owlNegativeObjectAssertion( X, P, Y )#0][+owlNegativeObjectAssertion( X, P, Y )<idx#0>#passive] --> true ;;
(occ rule) NegativeObjectAssertion @ [-owlNegativeObjectAssertion( X, P, Y )#1][-owlObjectPropertyAssertion( X, P, Y )<idx#2>] --> failure ;;
(occ rule) [-owlObjectAllValuesFrom( C, P, Y )#0][+owlObjectAllValuesFrom( C, P, Y )<idx#0>#passive] --> true ;;
(occ rule) [-owlObjectMaxCardinality( C, P, N )#0][+owlObjectMaxCardinality( C, P, N )<idx#1>#passive] --> true ;;
(occ rule) [-owlObjectMaxCardinality( C, P, 0 )#1][-owlClassAssertion( U, C, true )<idx#1>, -owlObjectPropertyAssertion( U, P, _ )<idx#0>] --> failure ;;
(occ rule) [-owlObjectMaxCardinality( C, P, 1 )#2][-owlClassAssertion( U, C, true )<idx#1>, -owlObjectPropertyAssertion( U, P, Y1 )<idx#0>, -owlObjectPropertyAssertion( U, P, Y2 )<idx#0>, ( !( Y1 == Y2 ) )] --> owlSameIndividual( Y1, Y2 ) ;;
(occ rule) [-owlObjectProperty( P )#0][+owlObjectProperty( P )<idx#0>#passive] --> true ;;
(occ rule) [+owlObjectProperty( P )#1][] --> ( owlSubObjectPropertyOf( P, P ), owlEquivalentObjectProperty( P, P ) ) ;;
(occ rule) [+owlObjectProperty( P )#2][+owlClassAssertion( U, C, true )<idx#3>, +owlHasValueObject( C, P, Y )<idx#3>] --> owlObjectPropertyAssertion( U, P, Y ) ;;
(occ rule) [-owlObjectPropertyAssertion( X, P, Y )#0][+owlObjectPropertyAssertion( X, P, Y )<idx#2>#passive] --> true ;;
(occ rule) NegativeObjectAssertion @ [-owlObjectPropertyAssertion( X, P, Y )#1][-owlNegativeObjectAssertion( X, P, Y )<idx#0>] --> failure ;;
(occ rule) DisjointObjProperty @ [-owlObjectPropertyAssertion( X, A, Y )#2][-owlObjectPropertyAssertion( X, B, Y )<idx#5>, -owlDisjointObjectProperty( A, B )<idx#0>] --> failure ;;
(occ rule) DisjointObjProperty @ [-owlObjectPropertyAssertion( X, B, Y )#3][-owlObjectPropertyAssertion( X, A, Y )<idx#5>, -owlDisjointObjectProperty( A, B )<idx#0>] --> failure ;;
(occ rule) irreflexiveProperty @ [-owlObjectPropertyAssertion( X, P, X )#4][-owlIrreflexiveObjectProperty( P )<idx#0>] --> failure ;;
(occ rule) subObjproperty @ [+owlObjectPropertyAssertion( X, P2, Y )#5][+owlSubObjectPropertyOf( P2, P1 )<idx#0>, ( !( P2 == P1 ) )] --> owlObjectPropertyAssertion( X, P1, Y ) ;;
(occ rule) objectPropertydomain @ [+owlObjectPropertyAssertion( X, P, Y )#6][+owlObjectPropertyDomain( P, DP )<idx#0>] --> owlClassAssertion( X, DP, true ) ;;
(occ rule) objectPropertyCoDomain @ [+owlObjectPropertyAssertion( X, P, Y )#7][+owlObjectPropertyRange( P, DP )<idx#0>] --> owlClassAssertion( Y, DP, true ) ;;
(occ rule) sameIndividual3 @ [+owlObjectPropertyAssertion( X, P, O )#8][+owlSameIndividual( X, Y )<idx#0>, ( !( X == Y ) )] --> owlObjectPropertyAssertion( Y, P, O ) ;;
(occ rule) sameIndividual5 @ [+owlObjectPropertyAssertion( X, P, O1 )#9][+owlSameIndividual( O1, O2 )<idx#0>, ( !( O1 == O2 ) )] --> owlObjectPropertyAssertion( X, P, O2 ) ;;
(occ rule) inverseProperty @ [+owlObjectPropertyAssertion( X, P1, Y )#10][+owlInverseObjectProperty( P1, P2 )<idx#1>] --> owlObjectPropertyAssertion( Y, P2, X ) ;;
(occ rule) symmetricProperty @ [+owlObjectPropertyAssertion( X, P, Y )#11][+owlSymmetricObjectProperty( P )<idx#0>] --> owlObjectPropertyAssertion( Y, P, X ) ;;
(occ rule) AsymmetricProperty1 @ [+owlObjectPropertyAssertion( X, P, Y )#12][+owlAsymmetricObjectProperty( P )<idx#0>] --> owlNegativeObjectAssertion( Y, P, X ) ;;
(occ rule) reflexiveProperty @ [+owlObjectPropertyAssertion( X, P, Y )#13][+owlReflexiveObjectProperty( P )<idx#0>] --> ( owlObjectPropertyAssertion( X, P, X ), owlObjectPropertyAssertion( Y, P, Y ) ) ;;
(occ rule) functionalObjProperty @ [+owlObjectPropertyAssertion( X, P, Y )#14][+owlObjectPropertyAssertion( X, P, Z )<idx#0>, ( !( Y == Z ) ), +owlFunctionalObjectProperty( P )<idx#0>] --> owlSameIndividual( Y, Z ) ;;
(occ rule) functionalObjProperty @ [+owlObjectPropertyAssertion( X, P, Z )#15][+owlObjectPropertyAssertion( X, P, Y )<idx#0>, ( !( Y == Z ) ), +owlFunctionalObjectProperty( P )<idx#0>] --> owlSameIndividual( Y, Z ) ;;
(occ rule) inverseFunctional @ [+owlObjectPropertyAssertion( X, P, Z )#16][+owlObjectPropertyAssertion( Y, P, Z )<idx#4>, ( !( X == Y ) ), +owlInverseFunctionalObjectProperty( P )<idx#0>] --> owlSameIndividual( X, Y ) ;;
(occ rule) inverseFunctional @ [+owlObjectPropertyAssertion( Y, P, Z )#17][+owlObjectPropertyAssertion( X, P, Z )<idx#4>, ( !( X == Y ) ), +owlInverseFunctionalObjectProperty( P )<idx#0>] --> owlSameIndividual( X, Y ) ;;
(occ rule) [+owlObjectPropertyAssertion( U, P, V )#18][+owlClassAssertion( V, Y, true )<idx#0>, +owlObjectSomeValuesFrom( C, P, Y )<idx#2>] --> owlClassAssertion( U, C, true ) ;;
(occ rule) [-owlObjectPropertyAssertion( U, P, V )#19][-logicalName( emptyString, V )<idx#2>, -owlClassAssertion( V, Y, true )<idx#0>, +owlClassAssertion( W, Y, true )<idx#1>, +owlObjectPropertyAssertion( U, P, W )<idx#2>, +logicalName( URI, W )<idx#1>#passive, ( !( URI == emptyString ) )] --> success ;;
(occ rule) [+owlObjectPropertyAssertion( U, P, W )#20][+owlClassAssertion( W, Y, true )<idx#0>, -owlClassAssertion( V, Y, true )<idx#1>, -logicalName( emptyString, V )<idx#2>, -owlObjectPropertyAssertion( U, P, V )<idx#2>, +logicalName( URI, W )<idx#1>#passive, ( !( URI == emptyString ) )] --> success ;;
(occ rule) [-owlObjectPropertyAssertion( U, P, _ )#21][-owlObjectMaxCardinality( C, P, 0 )<idx#2>, -owlClassAssertion( U, C, true )<idx#2>] --> failure ;;
(occ rule) [-owlObjectPropertyAssertion( U, P, Y1 )#22][-owlObjectMaxCardinality( C, P, 1 )<idx#2>, -owlClassAssertion( U, C, true )<idx#2>, -owlObjectPropertyAssertion( U, P, Y2 )<idx#0>, ( !( Y1 == Y2 ) )] --> owlSameIndividual( Y1, Y2 ) ;;
(occ rule) [-owlObjectPropertyAssertion( U, P, Y2 )#23][-owlObjectMaxCardinality( C, P, 1 )<idx#2>, -owlClassAssertion( U, C, true )<idx#2>, -owlObjectPropertyAssertion( U, P, Y1 )<idx#0>, ( !( Y1 == Y2 ) )] --> owlSameIndividual( Y1, Y2 ) ;;
(occ rule) [+owlObjectPropertyAssertion( U, P, Y )#24][+owlHasValueObject( C, P, Y )<idx#4>] --> owlClassAssertion( U, C, true ) ;;
(occ rule) ObjectPropertyChain @ [+owlObjectPropertyAssertion( X, P, Y )#25][+owlObjectPropertyChain( PC, P, 0, N )<idx#1>] --> constructPropertyChain( PC, 0, X, Y, N ) ;;
(occ rule) chainStep @ [+owlObjectPropertyAssertion( Y, P, Z )#26][+owlObjectPropertyChain( PC, P, J, N )<idx#2>, +constructPropertyChain( PC, I, X, Y, N )<idx#1>, ( I < N ), equalIncrement( J, I )] --> constructPropertyChain( PC, ( I + 1 ), X, Z, N ) ;;
(occ rule) [+owlObjectPropertyAssertion( X, P, V )#27][+owlObjectPropertyAssertion( Y, P, V )<idx#4>, -owlHasKeyCheck( C, X, Y, I, N )<idx#0>, +owlHasKey( C, P, I, N )<idx#1>] --> owlHasKeyCheck( C, X, Y, ( I + 1 ), N ) ;;
(occ rule) [+owlObjectPropertyAssertion( Y, P, V )#28][+owlObjectPropertyAssertion( X, P, V )<idx#4>, -owlHasKeyCheck( C, X, Y, I, N )<idx#0>, +owlHasKey( C, P, I, N )<idx#1>] --> owlHasKeyCheck( C, X, Y, ( I + 1 ), N ) ;;
(occ rule) [+owlObjectPropertyAssertion( X, P, Y )#29][+queryObjAssertion( P, ID )<idx#0>, +logicalName( URIX, X )<idx#1>#passive, +logicalName( URIY, Y )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(occ rule) [+owlObjectPropertyAssertion( X, P, X )#30][+queryObjAssertion( P, ID )<idx#0>, +logicalName( URIX, X )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIX ), ID ) ;;
(occ rule) [+owlObjectPropertyAssertion( X, P, O )#31][+queryObjAssertionSubject( P, O, ID )<idx#0>, +logicalName( URIX, X )<idx#1>#passive] --> ResultVec( makeVec( URIX, emptyString ), ID ) ;;
(occ rule) [+owlObjectPropertyAssertion( X, P, Y )#32][+querySubjectByObject( P, ID )<idx#0>, +logicalName( URIX, X )<idx#1>#passive, +logicalName( URIY, Y )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(occ rule) [+owlObjectPropertyAssertion( X, F, Y )#33][+owlClassAssertion( X, E, true )<idx#0>, +queryEngineeringStudents( E, F, G, H, K, ID )<idx#1>, +owlObjectPropertyAssertion( Y, G, Z )<idx#0>, +owlObjectPropertyAssertion( Z, H, K )<idx#2>, +logicalName( URIX, X )<idx#1>#passive, +logicalName( URIY, Y )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(occ rule) [+owlObjectPropertyAssertion( Y, G, Z )#34][+owlClassAssertion( X, E, true )<idx#3>, +queryEngineeringStudents( E, F, G, H, K, ID )<idx#2>, +owlObjectPropertyAssertion( X, F, Y )<idx#2>, +owlObjectPropertyAssertion( Z, H, K )<idx#2>, +logicalName( URIX, X )<idx#1>#passive, +logicalName( URIY, Y )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(occ rule) [+owlObjectPropertyAssertion( Z, H, K )#35][+owlClassAssertion( X, E, true )<idx#3>, +queryEngineeringStudents( E, F, G, H, K, ID )<idx#3>, +owlObjectPropertyAssertion( X, F, Y )<idx#0>, +owlObjectPropertyAssertion( Y, G, Z )<idx#2>, +logicalName( URIX, X )<idx#1>#passive, +logicalName( URIY, Y )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(occ rule) [+owlObjectPropertyAssertion( X, G, Z )#36][+owlClassAssertion( X, F, true )<idx#0>, +owlClassAssertion( S, E, true )<idx#3>, +queryComplexStudents( E, F, G, H, K, ID )<idx#1>, +owlObjectPropertyAssertion( Z, H, C )<idx#0>, +owlObjectPropertyAssertion( S, K, C )<idx#2>, +logicalName( URIS, S )<idx#1>#passive, +logicalName( URIC, C )<idx#1>#passive] --> ResultVec( makeVec( URIS, URIC ), ID ) ;;
(occ rule) [+owlObjectPropertyAssertion( Z, H, C )#37][+owlClassAssertion( S, E, true )<idx#3>, +owlClassAssertion( X, F, true )<idx#3>, +queryComplexStudents( E, F, G, H, K, ID )<idx#2>, +owlObjectPropertyAssertion( X, G, Z )<idx#2>, +owlObjectPropertyAssertion( S, K, C )<idx#2>, +logicalName( URIS, S )<idx#1>#passive, +logicalName( URIC, C )<idx#1>#passive] --> ResultVec( makeVec( URIS, URIC ), ID ) ;;
(occ rule) [+owlObjectPropertyAssertion( S, K, C )#38][+owlClassAssertion( S, E, true )<idx#0>, +owlClassAssertion( X, F, true )<idx#3>, +queryComplexStudents( E, F, G, H, K, ID )<idx#3>, +owlObjectPropertyAssertion( X, G, Z )<idx#0>, +owlObjectPropertyAssertion( Z, H, C )<idx#2>, +logicalName( URIS, S )<idx#1>#passive, +logicalName( URIC, C )<idx#1>#passive] --> ResultVec( makeVec( URIS, URIC ), ID ) ;;
(occ rule) ObjectPropertyChain @ [+owlObjectPropertyChain( PC, P, 0, N )#0][+owlObjectPropertyAssertion( X, P, Y )<idx#3>] --> constructPropertyChain( PC, 0, X, Y, N ) ;;
(occ rule) chainStep @ [+owlObjectPropertyChain( PC, P, J, N )#1][+constructPropertyChain( PC, I, X, Y, N )<idx#2>, ( I < N ), equalIncrement( J, I ), +owlObjectPropertyAssertion( Y, P, Z )<idx#0>] --> constructPropertyChain( PC, ( I + 1 ), X, Z, N ) ;;
(occ rule) [-owlObjectPropertyDomain( P, C )#0][+owlObjectPropertyDomain( P, C )<idx#1>#passive] --> true ;;
(occ rule) [+owlObjectPropertyDomain( P, C1 )#1][+owlSubclassOf( C1, C2 )<idx#1>, ( !( C1 == C2 ) )] --> owlObjectPropertyDomain( P, C2 ) ;;
(occ rule) [+owlObjectPropertyDomain( P2, C )#2][+owlSubObjectPropertyOf( P1, P2 )<idx#1>, ( !( P1 == P2 ) )] --> owlObjectPropertyDomain( P1, C ) ;;
(occ rule) objectPropertydomain @ [+owlObjectPropertyDomain( P, DP )#3][+owlObjectPropertyAssertion( X, P, Y )<idx#3>] --> owlClassAssertion( X, DP, true ) ;;
(occ rule) [-owlObjectPropertyRange( P, C )#0][+owlObjectPropertyRange( P, C )<idx#1>#passive] --> true ;;
(occ rule) [+owlObjectPropertyRange( P, C1 )#1][+owlSubclassOf( C1, C2 )<idx#1>, ( !( C1 == C2 ) )] --> owlObjectPropertyRange( P, C2 ) ;;
(occ rule) [+owlObjectPropertyRange( P2, C )#2][+owlSubObjectPropertyOf( P1, P2 )<idx#1>, ( !( P1 == P2 ) )] --> owlObjectPropertyRange( P1, C ) ;;
(occ rule) objectPropertyCoDomain @ [+owlObjectPropertyRange( P, DP )#3][+owlObjectPropertyAssertion( X, P, Y )<idx#3>] --> owlClassAssertion( Y, DP, true ) ;;
(occ rule) [-owlObjectSomeValuesFrom( C, P, Y )#0][+owlObjectSomeValuesFrom( C, P, Y )<idx#3>#passive] --> true ;;
(occ rule) [+owlObjectSomeValuesFrom( C1, P, Y )#1][+owlObjectSomeValuesFrom( C2, P, Y )<idx#2>, ( !( C1 == C2 ) )] --> owlEquivalentClass( C1, C2 ) ;;
(occ rule) [+owlObjectSomeValuesFrom( C2, P, Y )#2][+owlObjectSomeValuesFrom( C1, P, Y )<idx#2>, ( !( C1 == C2 ) )] --> owlEquivalentClass( C1, C2 ) ;;
(occ rule) [+owlObjectSomeValuesFrom( C, P, Y )#3][+owlClassAssertion( V, Y, true )<idx#1>, +owlObjectPropertyAssertion( U, P, V )<idx#4>] --> owlClassAssertion( U, C, true ) ;;
(occ rule) [+owlObjectSomeValuesFrom( C, P, Y )#4][+owlClassAssertion( U, C, true )<idx#1>] --> ( owlObjectPropertyAssertion( U, P, V ), logicalName( emptyString, V ), owlClassAssertion( V, Y, true ) ) ;;
(occ rule) hasValueSubsumption @ [+owlObjectSomeValuesFrom( SV, P, Y )#5][+owlClassAssertion( A, Y, true )<idx#1>, +owlHasValueObject( C, P, A )<idx#4>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionClass @ [+owlObjectSomeValuesFrom( SV, P, Y2 )#6][+owlClassAssertion( A, Y1, true )<idx#3>, +owlHasValueObject( C, P, A )<idx#4>, +owlSubclassOf( Y1, Y2 )<idx#0>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionProp @ [+owlObjectSomeValuesFrom( SV, P2, Y )#7][+owlClassAssertion( A, Y, true )<idx#1>, +owlSubObjectPropertyOf( P1, P2 )<idx#1>, +owlHasValueObject( C, P1, A )<idx#4>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionPropClass @ [+owlObjectSomeValuesFrom( SV, P2, Y2 )#8][+owlClassAssertion( A, Y1, true )<idx#3>, +owlSubclassOf( Y1, Y2 )<idx#0>, +owlHasValueObject( C, P1, A )<idx#1>, +owlSubObjectPropertyOf( P1, P2 )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) [-owlOneOf( C, S )#0][+owlOneOf( C, S )<idx#0>#passive] --> true ;;
(occ rule) [+owlOneOf( C, S )#1][] --> owlOneOfLoop( C, ( ( *S ) . begin(  ) ), ( ( *S ) . end(  ) ) ) ;;
(occ rule) [-owlOneOfLoop( C, ITEND, ITEND )#1][] --> success ;;
(occ rule) [-owlOneOfLoop( C, IT, ITEND )#2][] --> ( owlClassAssertion( ( *( *IT ) ), C, true ), owlOneOfLoop( C, ( std :: next( ( *IT ) ) ), ITEND ) ) ;;
(occ rule) [-owlPrefix( X, Y )#0][+owlPrefix( X, Y )<idx#0>#passive] --> true ;;
(occ rule) [-owlReflexiveObjectProperty( P )#0][+owlReflexiveObjectProperty( P )<idx#0>#passive] --> true ;;
(occ rule) reflexiveProperty @ [+owlReflexiveObjectProperty( P )#1][+owlObjectPropertyAssertion( X, P, Y )<idx#3>] --> ( owlObjectPropertyAssertion( X, P, X ), owlObjectPropertyAssertion( Y, P, Y ) ) ;;
(occ rule) [-owlSameIndividual( X, Y )#0][+owlSameIndividual( X, Y )<idx#1>#passive] --> true ;;
(occ rule) sameIndividual1 @ [+owlSameIndividual( X, Y )#1][( !( X == Y ) )] --> owlSameIndividual( Y, X ) ;;
(occ rule) sameIndividual2 @ [+owlSameIndividual( X, Y )#2][( !( X == Y ) ), +owlSameIndividual( Y, Z )<idx#0>, ( !( Y == Z ) ), ( !( X == Z ) )] --> owlSameIndividual( X, Z ) ;;
(occ rule) sameIndividual2 @ [+owlSameIndividual( Y, Z )#3][( !( Y == Z ) ), +owlSameIndividual( X, Y )<idx#2>, ( !( X == Y ) ), ( !( X == Z ) )] --> owlSameIndividual( X, Z ) ;;
(occ rule) sameIndividual3 @ [+owlSameIndividual( X, Y )#4][( !( X == Y ) ), +owlObjectPropertyAssertion( X, P, O )<idx#6>] --> owlObjectPropertyAssertion( Y, P, O ) ;;
(occ rule) sameIndividual4 @ [+owlSameIndividual( X, Y )#5][( !( X == Y ) ), +owlDataPropertyAssertion( X, P, O )<idx#0>] --> owlDataPropertyAssertion( Y, P, O ) ;;
(occ rule) sameIndividual5 @ [+owlSameIndividual( O1, O2 )#6][( !( O1 == O2 ) ), +owlObjectPropertyAssertion( X, P, O1 )<idx#1>] --> owlObjectPropertyAssertion( X, P, O2 ) ;;
(occ rule) sameIndividual6 @ [+owlSameIndividual( X, Y )#7][( !( X == Y ) ), +owlClassAssertion( X, C, B )<idx#4>] --> owlClassAssertion( Y, C, B ) ;;
(occ rule) DifferentIndividual @ [-owlSameIndividual( X, Y )#8][-owlDifferentIndividual( X, Y )<idx#0>] --> failure ;;
(occ rule) [-owlSubDataPropertyOf( A, B )#0][+owlSubDataPropertyOf( A, B )<idx#2>#passive] --> true ;;
(occ rule) [+owlSubDataPropertyOf( A, B )#1][+owlSubDataPropertyOf( B, C )<idx#0>, different( A, B, C )] --> owlSubDataPropertyOf( A, C ) ;;
(occ rule) [+owlSubDataPropertyOf( B, C )#2][+owlSubDataPropertyOf( A, B )<idx#1>, different( A, B, C )] --> owlSubDataPropertyOf( A, C ) ;;
(occ rule) [+owlSubDataPropertyOf( A, B )#3][( !( A == B ) ), +owlSubDataPropertyOf( B, A )<idx#2>] --> owlEquivalentDataProperty( A, B ) ;;
(occ rule) [+owlSubDataPropertyOf( B, A )#4][( !( A == B ) ), +owlSubDataPropertyOf( A, B )<idx#2>] --> owlEquivalentDataProperty( A, B ) ;;
(occ rule) [+owlSubDataPropertyOf( P1, P2 )#5][( !( P1 == P2 ) ), +owlDataPropertyDomain( P2, C )<idx#0>] --> owlDataPropertyDomain( P1, C ) ;;
(occ rule) [+owlSubDataPropertyOf( P1, P2 )#6][( !( P1 == P2 ) ), +owlDataPropertyRange( P2, C )<idx#0>] --> owlDataPropertyRange( P1, C ) ;;
(occ rule) subDataProperty @ [+owlSubDataPropertyOf( P2, P1 )#7][( !( P2 == P1 ) ), +owlDataPropertyAssertion( X, P2, Y )<idx#5>] --> owlDataPropertyAssertion( X, P1, Y ) ;;
(occ rule) [-owlSubObjectPropertyOf( A, B )#0][+owlSubObjectPropertyOf( A, B )<idx#2>#passive] --> true ;;
(occ rule) [+owlSubObjectPropertyOf( A, B )#1][+owlSubObjectPropertyOf( B, C )<idx#0>, different( A, B, C )] --> owlSubObjectPropertyOf( A, C ) ;;
(occ rule) [+owlSubObjectPropertyOf( B, C )#2][+owlSubObjectPropertyOf( A, B )<idx#1>, different( A, B, C )] --> owlSubObjectPropertyOf( A, C ) ;;
(occ rule) [+owlSubObjectPropertyOf( A, B )#3][( !( A == B ) ), +owlSubObjectPropertyOf( B, A )<idx#2>] --> owlEquivalentObjectProperty( A, B ) ;;
(occ rule) [+owlSubObjectPropertyOf( B, A )#4][( !( A == B ) ), +owlSubObjectPropertyOf( A, B )<idx#2>] --> owlEquivalentObjectProperty( A, B ) ;;
(occ rule) [+owlSubObjectPropertyOf( P1, P2 )#5][( !( P1 == P2 ) ), +owlObjectPropertyDomain( P2, C )<idx#0>] --> owlObjectPropertyDomain( P1, C ) ;;
(occ rule) [+owlSubObjectPropertyOf( P1, P2 )#6][( !( P1 == P2 ) ), +owlObjectPropertyRange( P2, C )<idx#0>] --> owlObjectPropertyRange( P1, C ) ;;
(occ rule) subObjproperty @ [+owlSubObjectPropertyOf( P2, P1 )#7][( !( P2 == P1 ) ), +owlObjectPropertyAssertion( X, P2, Y )<idx#3>] --> owlObjectPropertyAssertion( X, P1, Y ) ;;
(occ rule) hasValueSubsumptionProp @ [+owlSubObjectPropertyOf( P1, P2 )#8][+owlClassAssertion( A, Y, true )<idx#3>, +owlHasValueObject( C, P1, A )<idx#4>, +owlObjectSomeValuesFrom( SV, P2, Y )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionPropClass @ [+owlSubObjectPropertyOf( P1, P2 )#9][+owlClassAssertion( A, Y1, true )<idx#3>, +owlHasValueObject( C, P1, A )<idx#4>, +owlSubclassOf( Y1, Y2 )<idx#1>, +owlObjectSomeValuesFrom( SV, P2, Y2 )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) [-owlSubclassOf( A, B )#0][+owlSubclassOf( A, B )<idx#0>#passive] --> true ;;
(occ rule) [+owlSubclassOf( C1, C2 )#1][] --> ( owlClass( C1 ), owlClass( C2 ) ) ;;
(occ rule) [+owlSubclassOf( A, B )#2][+owlSubclassOf( B, C )<idx#1>, different( A, B, C )] --> owlSubclassOf( A, C ) ;;
(occ rule) [+owlSubclassOf( B, C )#3][+owlSubclassOf( A, B )<idx#2>, different( A, B, C )] --> owlSubclassOf( A, C ) ;;
(occ rule) [+owlSubclassOf( A, B )#4][( !( A == B ) ), +owlSubclassOf( B, A )<idx#0>] --> owlEquivalentClass( A, B ) ;;
(occ rule) [+owlSubclassOf( B, A )#5][( !( A == B ) ), +owlSubclassOf( A, B )<idx#0>] --> owlEquivalentClass( A, B ) ;;
(occ rule) [+owlSubclassOf( C1, C2 )#6][( !( C1 == C2 ) ), +owlObjectPropertyDomain( P, C1 )<idx#2>] --> owlObjectPropertyDomain( P, C2 ) ;;
(occ rule) [+owlSubclassOf( C1, C2 )#7][( !( C1 == C2 ) ), +owlObjectPropertyRange( P, C1 )<idx#2>] --> owlObjectPropertyRange( P, C2 ) ;;
(occ rule) subclass @ [+owlSubclassOf( A, B )#8][( !( A == B ) ), +owlClassAssertion( X, A, true )<idx#1>] --> owlClassAssertion( X, B, true ) ;;
(occ rule) [+owlSubclassOf( A, V )#9][+owlUnionClass( C, V )<idx#0>, ( !( C == A ) )] --> owlSubclassOf( A, C ) ;;
(occ rule) r7 @ [+owlSubclassOf( C2, C1 )#10][( !( C1 == C2 ) ), +owlIntersectionClass( C1, Component, _ )<idx#4>] --> owlSubclassOf( C2, Component ) ;;
(occ rule) r8a @ [+owlSubclassOf( A, V )#11][+owlIntersectionClass( C, V, 0 )<idx#2>] --> intersectionSubclassCheck( C, A, 1 ) ;;
(occ rule) r8b @ [+owlSubclassOf( A, V )#12][+owlIntersectionClass( C, V, I )<idx#3>, ( I > 0 ), +intersectionSubclassCheck( C, A, I )<idx#0>] --> intersectionSubclassCheck( C, A, ( I + 1 ) ) ;;
(occ rule) hasValueSubsumptionClass @ [+owlSubclassOf( Y1, Y2 )#13][+owlClassAssertion( A, Y1, true )<idx#1>, +owlHasValueObject( C, P, A )<idx#1>, +owlObjectSomeValuesFrom( SV, P, Y2 )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) hasValueSubsumptionPropClass @ [+owlSubclassOf( Y1, Y2 )#14][+owlClassAssertion( A, Y1, true )<idx#1>, +owlHasValueObject( C, P1, A )<idx#1>, +owlSubObjectPropertyOf( P1, P2 )<idx#0>, +owlObjectSomeValuesFrom( SV, P2, Y2 )<idx#2>] --> owlSubclassOf( C, SV ) ;;
(occ rule) [+owlSubclassOf( X, Y )#15][( !( X == Y ) ), +querySuperClassOf( X )<idx#0>, +logicalName( URIY, Y )<idx#1>#passive] --> ( querySuperClassOf( Y ), queryEquivalentClass( X ), res( URIY ) ) ;;
(occ rule) r_querySubClassOf1 @ [+owlSubclassOf( Y, X )#17][( !( X == Y ) ), +querySubClassOf( X )<idx#0>, +logicalName( URIY, Y )<idx#1>#passive] --> ( querySubClassOf( Y ), queryEquivalentClass( X ), res( URIY ) ) ;;
(occ rule) [+owlSubclassOf( X, Y )#19][+logicalName( owlNothing, OwlNothingVar )<idx#0>#passive, +logicalName( URIX, X )<idx#1>#passive, ( !( URIX == owlNothing ) ), +logicalName( URIY, Y )<idx#1>#passive, +classification(  )] --> resultClassification( URIX, URIY ) ;;
(occ rule) [+owlSubclassOf( X, X )#20][+logicalName( URIX, X )<idx#1>#passive, +classification(  )] --> resultClassification( URIX, URIX ) ;;
(occ rule) [-owlSymmetricObjectProperty( P )#0][+owlSymmetricObjectProperty( P )<idx#0>#passive] --> true ;;
(occ rule) symmetricProperty @ [+owlSymmetricObjectProperty( P )#1][+owlObjectPropertyAssertion( X, P, Y )<idx#3>] --> owlObjectPropertyAssertion( Y, P, X ) ;;
(occ rule) [-owlTransitiveObjectProperty( P )#0][+owlTransitiveObjectProperty( P )<idx#0>#passive] --> true ;;
(occ rule) [-owlUnionClass( C, V )#0][+owlUnionClass( C, V )<idx#1>#passive] --> true ;;
(occ rule) [-owlUnionClass( C, V )#1][+owlClassAssertion( X, V, true )<idx#1>] --> owlClassAssertion( X, C, true ) ;;
(occ rule) [+owlUnionClass( C, V )#2][+owlSubclassOf( A, V )<idx#2>, ( !( C == A ) )] --> owlSubclassOf( A, C ) ;;
(occ rule) [-owlUnionOf( C, S )#0][+owlUnionOf( C, S )<idx#0>#passive] --> true ;;
(occ rule) [+owlUnionOf( C, S )#1][] --> owlUnionOfLoop( C, ( ( *S ) . begin(  ) ), ( ( *S ) . end(  ) ) ) ;;
(occ rule) [+owlUnionOf( C1, S )#2][+owlUnionOf( C2, S )<idx#1>] --> owlEquivalentClass( C1, C2 ) ;;
(occ rule) [+owlUnionOf( C2, S )#3][+owlUnionOf( C1, S )<idx#1>] --> owlEquivalentClass( C1, C2 ) ;;
(occ rule) [-owlUnionOfLoop( C, ITEND, ITEND )#0][] --> success ;;
(occ rule) [-owlUnionOfLoop( C, IT, ITEND )#1][] --> ( owlUnionClass( C, ( *( *IT ) ) ), owlUnionOfLoop( C, ( std :: next( ( *IT ) ) ), ITEND ) ) ;;
(occ rule) [-queryClassification( X )#0][+queryClassification( X )<idx#0>#passive] --> true ;;
(occ rule) r_queryClassification1 @ [+queryClassification( X )#1][+owlClassAssertion( X, C, true )<idx#0>, +logicalName( URIC, C )<idx#1>#passive] --> ( res( URIC ), querySuperClassOf( C ), queryEquivalentClass( C ) ) ;;
(occ rule) [-queryClassificationReal( X )#0][+queryClassificationReal( X )<idx#0>#passive] --> true ;;
(occ rule) [-queryClassificationTemp( X )#0][+queryClassificationTemp( X )<idx#0>#passive] --> true ;;
(occ rule) [-queryClassificationTempUri( URI )#0][+queryClassificationTempUri( URI )<idx#0>#passive] --> true ;;
(occ rule) [-queryClassificationUri( URI )#0][+queryClassificationUri( URI )<idx#0>#passive] --> true ;;
(occ rule) [+queryClassificationUri( URIX )#1][+logicalName( URIX, X )<idx#0>#passive] --> queryClassification( X ) ;;
(occ rule) [+queryComplexStudents( E, F, G, H, K, ID )#0][+owlClassAssertion( S, E, true )<idx#1>, +owlClassAssertion( X, F, true )<idx#1>, +owlObjectPropertyAssertion( X, G, Z )<idx#0>, +owlObjectPropertyAssertion( Z, H, C )<idx#0>, +owlObjectPropertyAssertion( S, K, C )<idx#2>, +logicalName( URIS, S )<idx#1>#passive, +logicalName( URIC, C )<idx#1>#passive] --> ResultVec( makeVec( URIS, URIC ), ID ) ;;
(occ rule) [-queryComplexStudents( E, F, G, H, K, ID )#1][] --> success ;;
(occ rule) [-queryComplexStudentsUri( URIE, URIF, URIG, URIH, URIK )#0][] --> queryComplexStudentsWithId( URIE, URIF, URIG, URIH, URIK, get_next_id(  ) ) ;;
(occ rule) [-queryComplexStudentsWithId( URIE, URIF, URIG, URIH, URIK, ID )#0][+logicalName( URIE, E )<idx#0>, +logicalName( URIF, F )<idx#0>, +logicalName( URIG, G )<idx#0>, +logicalName( URIH, H )<idx#0>, +logicalName( URIK, K )<idx#0>] --> queryComplexStudents( E, F, G, H, K, ID ) ;;
(occ rule) [-queryComplexStudentsWithId( URIE, URIF, URIG, URIH, URIK, ID )#1][] --> success ;;
(occ rule) [-queryDataAssertion( P, ID )#0][+queryDataAssertion( P, ID )<idx#1>#passive] --> true ;;
(occ rule) [+queryDataAssertion( P, ID )#1][+owlDataPropertyAssertion( X, P, Y )<idx#5>, +logicalName( URIX, X )<idx#1>] --> ResultVec( makeVec( URIX, valueToString( Y ) ), ID ) ;;
(occ rule) [-queryDataAssertion( P, ID )#2][] --> success ;;
(occ rule) [-queryDataAssertionUri( URIP )#1][] --> queryDataAssertionWithId( URIP, get_next_id(  ) ) ;;
(occ rule) [-queryDataAssertionWithId( URIP, ID )#0][+logicalName( URIP, P )<idx#0>] --> queryDataAssertion( P, ID ) ;;
(occ rule) [-queryDataAssertionWithId( URIP, ID )#1][] --> success ;;
(occ rule) [+queryEngineeringStudents( E, F, G, H, K, ID )#0][+owlClassAssertion( X, E, true )<idx#1>, +owlObjectPropertyAssertion( X, F, Y )<idx#0>, +owlObjectPropertyAssertion( Y, G, Z )<idx#0>, +owlObjectPropertyAssertion( Z, H, K )<idx#2>, +logicalName( URIX, X )<idx#1>#passive, +logicalName( URIY, Y )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(occ rule) [-queryEngineeringStudents( E, F, G, H, K, ID )#1][] --> success ;;
(occ rule) [-queryEngineeringStudentsUri( URIE, URIF, URIG, URIH, URIK )#0][] --> queryEngineeringStudentsWithId( URIE, URIF, URIG, URIH, URIK, get_next_id(  ) ) ;;
(occ rule) [-queryEngineeringStudentsWithId( URIE, URIF, URIG, URIH, URIK, ID )#0][+logicalName( URIE, E )<idx#0>, +logicalName( URIF, F )<idx#0>, +logicalName( URIG, G )<idx#0>, +logicalName( URIH, H )<idx#0>, +logicalName( URIK, K )<idx#0>] --> queryEngineeringStudents( E, F, G, H, K, ID ) ;;
(occ rule) [-queryEngineeringStudentsWithId( URIE, URIF, URIG, URIH, URIK, ID )#1][] --> success ;;
(occ rule) [-queryEquivalentClass( X )#0][+queryEquivalentClass( X )<idx#0>#passive] --> true ;;
(occ rule) [+queryEquivalentClass( X )#1][+owlEquivalentClass( X, Y )<idx#0>, ( !( X == Y ) ), +logicalName( URIY, Y )<idx#1>#passive] --> res( URIY ) ;;
(occ rule) [-queryEquivalentClassReal( I, X )#0][+queryEquivalentClassReal( I, X )<idx#0>#passive] --> true ;;
(occ rule) [-queryFullUri( X )#0][+queryFullUri( X )<idx#0>#passive] --> true ;;
(occ rule) rule2 @ [-queryInstance( X, C )#1][+owlClassAssertion( X, C, true )<idx#2>] --> afficher( "true" ) ;;
(occ rule) rule3 @ [-queryInstance( X, C )#2][] --> afficher( "false" ) ;;
(occ rule) [-queryInstanceURI( URIX, URIC )#0][+queryInstanceURI( URIX, URIC )<idx#0>#passive] --> true ;;
(occ rule) rule1 @ [-queryInstanceURI( URIX, URIC )#1][+logicalName( URIC, C )<idx#0>#passive, +logicalName( URIX, X )<idx#0>#passive] --> queryInstance( X, C ) ;;
(occ rule) [-queryInstances( C, ID )#0][+queryInstances( C, ID )<idx#1>#passive] --> true ;;
(occ rule) [+queryInstances( C, ID )#1][+owlClassAssertion( X, C, true )<idx#1>, +logicalName( URIX, X )<idx#1>#passive] --> ResultVec( makeVec( URIX, emptyString ), ID ) ;;
(occ rule) [-queryInstances( C, ID )#2][] --> success ;;
(occ rule) [-queryInstancesURI( URIC )#1][] --> queryInstancesWithId( URIC, get_next_id(  ) ) ;;
(occ rule) [-queryInstancesWithId( URIC, ID )#0][+logicalName( URIC, C )<idx#0>] --> queryInstances( C, ID ) ;;
(occ rule) [-queryInstancesWithId( URIC, ID )#1][] --> success ;;
(occ rule) [-queryObjAssertion( P, ID )#0][+queryObjAssertion( P, ID )<idx#1>#passive] --> true ;;
(occ rule) [+queryObjAssertion( P, ID )#1][+owlObjectPropertyAssertion( X, P, Y )<idx#3>, +logicalName( URIX, X )<idx#1>#passive, +logicalName( URIY, Y )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(occ rule) [+queryObjAssertion( P, ID )#2][+owlObjectPropertyAssertion( X, P, X )<idx#3>, +logicalName( URIX, X )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIX ), ID ) ;;
(occ rule) [-queryObjAssertion( P, ID )#3][] --> success ;;
(occ rule) [-queryObjAssertionClass( P, C )#0][+queryObjAssertionClass( P, C )<idx#0>#passive] --> true ;;
(occ rule) [-queryObjAssertionClassUri( URIP, URIC )#0][+queryObjAssertionClassUri( URIP, URIC )<idx#0>#passive] --> true ;;
(occ rule) [-queryObjAssertionSubject( P, O, ID )#0][+queryObjAssertionSubject( P, O, ID )<idx#1>#passive] --> true ;;
(occ rule) [-queryObjAssertionSubject( P, O, ID )#1][+queryObjAssertionSubject( P, O, ID )<idx#1>#passive] --> true ;;
(occ rule) [+queryObjAssertionSubject( P, O, ID )#2][+owlObjectPropertyAssertion( X, P, O )<idx#4>, +logicalName( URIX, X )<idx#1>#passive] --> ResultVec( makeVec( URIX, emptyString ), ID ) ;;
(occ rule) [-queryObjAssertionSubject( P, O, ID )#3][] --> success ;;
(occ rule) [-queryObjAssertionSubjectUri( URIP, URIO )#1][] --> queryObjAssertionSubjectWithId( URIP, URIO, get_next_id(  ) ) ;;
(occ rule) [-queryObjAssertionSubjectWithId( URIP, URIO, ID )#0][+logicalName( URIP, P )<idx#0>, +logicalName( URIO, O )<idx#0>] --> queryObjAssertionSubject( P, O, ID ) ;;
(occ rule) [-queryObjAssertionSubjectWithId( URIP, URIO, ID )#1][] --> success ;;
(occ rule) [-queryObjAssertionUri( URIP )#1][] --> queryObjAssertionWithId( URIP, get_next_id(  ) ) ;;
(occ rule) [-queryObjAssertionWithId( URIP, ID )#0][+logicalName( URIP, P )<idx#0>] --> queryObjAssertion( P, ID ) ;;
(occ rule) [-queryObjAssertionWithId( URIP, ID )#1][] --> success ;;
(occ rule) [-querySubClassOf( X )#0][+querySubClassOf( X )<idx#0>#passive] --> true ;;
(occ rule) r_querySubClassOf1 @ [+querySubClassOf( X )#1][+owlSubclassOf( Y, X )<idx#2>, ( !( X == Y ) ), +logicalName( URIY, Y )<idx#1>#passive] --> ( querySubClassOf( Y ), queryEquivalentClass( X ), res( URIY ) ) ;;
(occ rule) [-querySubClassOfClass( X, Y )#1][+owlSubclassOf( X, Y )<idx#0>] --> afficher( "true" ) ;;
(occ rule) [-querySubClassOfClass( X, Y )#2][] --> afficher( "false" ) ;;
(occ rule) [-querySubClassOfClassUri( URIX, URIY )#0][+querySubClassOfClassUri( URIX, URIY )<idx#0>#passive] --> true ;;
(occ rule) r_querySubClassOfClassURI @ [-querySubClassOfClassUri( URIX, URIY )#1][+logicalName( URIX, X )<idx#0>#passive, +logicalName( URIY, Y )<idx#0>#passive] --> querySubClassOfClass( X, Y ) ;;
(occ rule) [-querySubClassOfUri( URI )#0][+querySubClassOfUri( URI )<idx#0>#passive] --> true ;;
(occ rule) [+querySubClassOfUri( URIC )#1][+logicalName( URIC, X )<idx#0>#passive] --> ( querySubClassOf( X ), res( URIC ) ) ;;
(occ rule) [-querySubjectByObject( P, ID )#0][+querySubjectByObject( P, ID )<idx#1>#passive] --> true ;;
(occ rule) [+querySubjectByObject( P, ID )#1][+owlObjectPropertyAssertion( X, P, Y )<idx#3>, +logicalName( URIX, X )<idx#1>#passive, +logicalName( URIY, Y )<idx#1>#passive] --> ResultVec( makeVec( URIX, URIY ), ID ) ;;
(occ rule) [-querySubjectByObject( P, ID )#2][] --> success ;;
(occ rule) [-querySubjectByObjectUri( URIP )#1][] --> querySubjectByObjectWithId( URIP, get_next_id(  ) ) ;;
(occ rule) [-querySubjectByObjectWithId( URIP, ID )#0][+logicalName( URIP, P )<idx#0>] --> querySubjectByObject( P, ID ) ;;
(occ rule) [-querySubjectByObjectWithId( URIP, ID )#1][] --> success ;;
(occ rule) [-querySuperClassOf( X )#0][+querySuperClassOf( X )<idx#0>#passive] --> true ;;
(occ rule) [+querySuperClassOf( X )#1][+owlSubclassOf( X, Y )<idx#1>, ( !( X == Y ) ), +logicalName( URIY, Y )<idx#1>#passive] --> ( querySuperClassOf( Y ), queryEquivalentClass( X ), res( URIY ) ) ;;
(occ rule) [-querySuperClassOfClass( X, Y )#1][+owlSubclassOf( Y, X )<idx#0>] --> afficher( "true" ) ;;
(occ rule) [-querySuperClassOfClass( X, Y )#2][] --> afficher( "false" ) ;;
(occ rule) [-querySuperClassOfClassUri( URIX, URIY )#0][+querySuperClassOfClassUri( URIX, URIY )<idx#0>#passive] --> true ;;
(occ rule) r_querySuperClassOfClassURI @ [-querySuperClassOfClassUri( URIX, URIY )#1][+logicalName( URIX, X )<idx#0>#passive, +logicalName( URIY, Y )<idx#0>#passive] --> querySuperClassOfClass( X, Y ) ;;
(occ rule) [-querySuperClassOfReal( I, C )#0][+querySuperClassOfReal( I, C )<idx#0>#passive] --> true ;;
(occ rule) [-querySuperClassOfUri( URI )#0][+querySuperClassOfUri( URI )<idx#0>#passive] --> true ;;
(occ rule) [+querySuperClassOfUri( URIC )#1][+logicalName( URIC, X )<idx#0>#passive] --> ( querySuperClassOf( X ), res( URIC ) ) ;;
(occ rule) realisation @ [+realisation(  )#0][+owlClassAssertion( X, C, true )<idx#3>, +logicalName( URIC, C )<idx#1>#passive, +logicalName( URIX, X )<idx#1>#passive] --> resultRealisation( URIX, URIC ) ;;
(occ rule) realisationPunning @ [+realisation(  )#1][+owlClassAssertion( X, X, true )<idx#3>, +logicalName( URI, X )<idx#1>#passive] --> resultRealisation( URI, URI ) ;;
(occ rule) [-res( X )#0][+res( X )<idx#0>#passive] --> true ;;
(occ rule) [+res( URIC )#1][] --> afficher( URIC ) ;;
(occ rule) [-resultClassification( X, Y )#0][+resultClassification( X, Y )<idx#1>#passive] --> true ;;
(occ rule) [-resultClassification( URIX, URIY )#1][+logicalName( URIX, X )<idx#0>#passive, +owlEquivalentClass( X, Y )<idx#0>, +logicalName( URIY, Y )<idx#2>#passive] --> true ;;
(occ rule) [+resultClassification( URIX, URIY )#2][( !prefixIntern( URIY ) ), ( !prefixIntern( URIX ) )] --> stockerClassification( URIX, URIY ) ;;
(occ rule) [-resultRealisation( X, Y )#0][+resultRealisation( X, Y )<idx#0>#passive] --> true ;;
(occ rule) [+resultRealisation( URIX, URIY )#1][( !prefixIntern( URIY ) )] --> stockerRealisation( URIX, URIY ) ;;

(constraint store) owlPrefix( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) owlClass( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlDataProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlNamedIndividual( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlSubclassOf( ( ?int ), ( ?int ) ), indexes: { <0,1>, <0>, <1> }, persistent
(constraint store) owlEquivalentClass( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1> }, persistent
(constraint store) owlSubDataPropertyOf( ( ?int ), ( ?int ) ), indexes: { <0>, <1>, <0,1> }, persistent
(constraint store) owlSubObjectPropertyOf( ( ?int ), ( ?int ) ), indexes: { <0>, <1>, <0,1> }, persistent
(constraint store) owlEquivalentDataProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) owlEquivalentObjectProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) owlObjectPropertyDomain( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1>, <1> }, persistent
(constraint store) owlDataPropertyDomain( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1> }, persistent
(constraint store) owlObjectPropertyRange( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1>, <1> }, persistent
(constraint store) owlClassAssertion( ( ?int ), ( ?int ), ( +bool ) ), indexes: { <0,2>, <1,2>, <0,1,2>, <2>, <0> }, persistent
(constraint store) owlDisjointClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) owlNegativeObjectAssertion( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0,1,2> }, persistent
(constraint store) owlObjectPropertyAssertion( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0,1>, <2>, <0,1,2>, <1>, <1,2>, <0,2>, <0> }, persistent
(constraint store) owlSameIndividual( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1>, <1> }, persistent
(constraint store) owlDifferentIndividual( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) owlInverseObjectProperty( ( ?int ), ( ?int ) ), indexes: { <0,1>, <0> }, persistent
(constraint store) owlSymmetricObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlAsymmetricObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlDisjointObjectProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) owlDisjointDataProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) owlReflexiveObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlIrreflexiveObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlFunctionalObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlFunctionalDataProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlInverseFunctionalObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlTransitiveObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) owlDataPropertyAssertion( ( ?int ), ( ?int ), ( +Value ) ), indexes: { <0>, <0,1>, <0,1,2>, <0,2>, <1,2>, <1>, <2> }, persistent
(constraint store) owlNegativeDataAssertion( ( ?int ), ( ?int ), ( +Value ) ), indexes: { <0,1,2> }, persistent
(constraint store) owlDataPropertyRange( ( ?int ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0>, <0,1> }, persistent
(constraint store) owlUnionClass( ( ?int ), ( ?int ) ), indexes: { <1>, <0,1> }, persistent
(constraint store) owlUnionOf( ( ?int ), ( +LogicalVarSet ) ), indexes: { <0,1>, <1> }, persistent
(constraint store) owlUnionOfLoop( ( ?int ), ( +LogicalVarSetIterator ), ( +LogicalVarSetIterator ) ), persistent
(constraint store) owlIntersectionOf( ( ?int ), ( +LogicalVarSet ) ), indexes: { <0,1> }, persistent
(constraint store) owlIntersectionClass( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,2>, <0,1,2>, <1,2>, <1>, <0> }, persistent
(constraint store) owlIntersectionOfLoop( ( ?int ), ( +LogicalVarSetIterator ), ( +LogicalVarSetIterator ), ( +int ) ), indexes: { <0,3>, <0,1,2,3> }, persistent
(constraint store) intersectionSubclassCheck( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1,2>, <0,2> }, persistent
(constraint store) owlCandidatsIntersection( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1,2>, <1,2> }, persistent
(constraint store) owlObjectAllValuesFrom( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0,1,2> }, persistent
(constraint store) owlDataAllValuesFrom( ( ?int ), ( ?int ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0,1,2> }, persistent
(constraint store) owlObjectSomeValuesFrom( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <2>, <0>, <1,2>, <0,1,2> }, persistent
(constraint store) owlDataSomeValuesFrom( ( ?int ), ( ?int ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0>, <1>, <0,1,2> }, persistent
(constraint store) owlDataValue( ( +Value ), ( +( std :: string ) ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0,1>, <0>, <1>, <0,1,2> }, persistent
(constraint store) owlComplementOf( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) owlObjectMaxCardinality( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,2>, <0,1,2>, <1,2> }, persistent
(constraint store) owlDataMaxCardinality( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,2>, <0,1,2>, <1,2> }, persistent
(constraint store) owlHasValueObject( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0>, <2>, <0,1,2>, <0,1>, <1,2> }, persistent
(constraint store) owlOneOf( ( ?int ), ( +LogicalVarSet ) ), indexes: { <0,1> }, persistent
(constraint store) owlOneOfLoop( ( ?int ), ( +LogicalVarSetIterator ), ( +LogicalVarSetIterator ) ), indexes: { <0,1,2> }, persistent
(constraint store) owlObjectPropertyChain( ( ?int ), ( ?int ), ( +int ), ( +int ) ), indexes: { <0,3>, <1,2>, <1> }, persistent
(constraint store) constructPropertyChain( ( ?int ), ( +int ), ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1,2,3,4>, <0,3,4>, <0,4> }, persistent
(constraint store) owlHasKey( ( ?int ), ( ?int ), ( +int ), ( +int ) ), indexes: { <0,2>, <0,1,2,3>, <0,2,3> }, persistent
(constraint store) owlHasKeyCheck( ( ?int ), ( ?int ), ( ?int ), ( +int ), ( +int ) ), indexes: { <1,2>, <0,3,4>, <0,1,2,3,4> }, persistent
(constraint store) querySuperClassOfUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint store) querySuperClassOfClassUri( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
(constraint store) querySubClassOfUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint store) querySubClassOfClassUri( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
(constraint store) querySuperClassOf( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) querySuperClassOfReal( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) querySubClassOf( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) querySubClassOfClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) querySuperClassOfClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) queryClassification( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) queryClassificationReal( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) queryClassificationUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint store) queryClassificationTemp( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) queryClassificationTempUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint store) queryInstanceURI( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
(constraint store) queryInstance( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) queryInstancesURI( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint store) queryInstances( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
(constraint store) queryObjAssertionUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint store) queryObjAssertion( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
(constraint store) querySubjectByObjectUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint store) querySubjectByObject( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
(constraint store) queryDataAssertionUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint store) queryDataAssertion( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
(constraint store) queryEngineeringStudentsUri( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ) ), persistent
(constraint store) queryEngineeringStudents( ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( +int ) ), indexes: { <0>, <0,1>, <0,2>, <0,3,4> }, persistent
(constraint store) queryComplexStudentsUri( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ) ), persistent
(constraint store) queryComplexStudents( ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1>, <0,1,2>, <0,1,3>, <0,1,4> }, persistent
(constraint store) queryObjAssertionSubjectUri( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
(constraint store) queryObjAssertionSubject( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1>, <0,1,2> }, persistent
(constraint store) queryObjAssertionClassUri( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) queryObjAssertionClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) queryEquivalentClass( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) queryEquivalentClassReal( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
(constraint store) res( ( +( std :: string ) ) ), indexes: { <0> }, persistent
(constraint store) resultRealisation( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
(constraint store) classification(  ), persistent
(constraint store) resultClassification( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0>, <0,1> }, persistent
(constraint store) queryFullUri( ( ?int ) ), indexes: { <0> }, persistent
(constraint store) logicalName( ( +( std :: string ) ), ( ?int ) ), indexes: { <0>, <1>, <0,1> }, persistent
(constraint store) realisation(  ), persistent
(constraint store) queryisMemberOf(  ), persistent
(constraint store) ResultVec( ( +StringSet ), ( +int ) ), indexes: { <0,1> }, persistent
(constraint store) queryInstancesWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
(constraint store) queryObjAssertionWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
(constraint store) queryDataAssertionWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
(constraint store) querySubjectByObjectWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
(constraint store) queryObjAssertionSubjectWithId( ( +( std :: string ) ), ( +( std :: string ) ), ( +int ) ), indexes: { <0>, <1> }, persistent
(constraint store) queryEngineeringStudentsWithId( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +int ) ), indexes: { <0>, <1>, <2>, <3>, <4> }, persistent
(constraint store) queryComplexStudentsWithId( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +int ) ), indexes: { <0>, <1>, <2>, <3>, <4> }, persistent
*/
//----------------------- START INCLUDE HEADER ---------------------
#include <chrpp.hh>
#include "include/AnySimpleType.h"
#include <iostream>
#include "include/constants.h"   // owlThing, owlNothing, emptyString — usati in decine di regole
#include "include/types.h"       // LogicalVarSet, StringSet, LogicalVarSetIterator, get_next_id()
#include "include/utils.h"
#include "include/chr_traits.h"

//----------------------- END INCLUDE HEADER ---------------------
#define __CHRPPC_MAJOR__ 1
#define __CHRPPC_MINOR__ 90
#line 1 "/home/user/owl-chr/owlChrpp/owlrules.chrpp"
#include <chrpp.hh>
class OWL2 {
	unsigned long int next_free_constraint_id = 1;
	//(constraint store) owlPrefix( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct owlPrefix {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlPrefix_constraint_store && _space->owlPrefix_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlPrefix(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlPrefix::Constraint_store_t > owlPrefix_constraint_store{ chr::make_shared< typename owlPrefix::Constraint_store_t >("owlPrefix") };
	//(constraint store) owlClass( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlClass {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlClass_constraint_store && _space->owlClass_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlClass(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlClass::Constraint_store_t > owlClass_constraint_store{ chr::make_shared< typename owlClass::Constraint_store_t >("owlClass") };
	//(constraint store) owlObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlObjectProperty_constraint_store && _space->owlObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlObjectProperty::Constraint_store_t > owlObjectProperty_constraint_store{ chr::make_shared< typename owlObjectProperty::Constraint_store_t >("owlObjectProperty") };
	//(constraint store) owlDataProperty( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlDataProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDataProperty_constraint_store && _space->owlDataProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDataProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDataProperty::Constraint_store_t > owlDataProperty_constraint_store{ chr::make_shared< typename owlDataProperty::Constraint_store_t >("owlDataProperty") };
	//(constraint store) owlNamedIndividual( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlNamedIndividual {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlNamedIndividual_constraint_store && _space->owlNamedIndividual_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlNamedIndividual(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlNamedIndividual::Constraint_store_t > owlNamedIndividual_constraint_store{ chr::make_shared< typename owlNamedIndividual::Constraint_store_t >("owlNamedIndividual") };
	//(constraint store) owlSubclassOf( ( ?int ), ( ?int ) ), indexes: { <0,1>, <0>, <1> }, persistent
public:
	struct owlSubclassOf {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<0>, chr::LNS::Index<1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlSubclassOf_constraint_store && _space->owlSubclassOf_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlSubclassOf(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlSubclassOf::Constraint_store_t > owlSubclassOf_constraint_store{ chr::make_shared< typename owlSubclassOf::Constraint_store_t >("owlSubclassOf") };
	//(constraint store) owlEquivalentClass( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1> }, persistent
public:
	struct owlEquivalentClass {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlEquivalentClass_constraint_store && _space->owlEquivalentClass_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlEquivalentClass(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlEquivalentClass::Constraint_store_t > owlEquivalentClass_constraint_store{ chr::make_shared< typename owlEquivalentClass::Constraint_store_t >("owlEquivalentClass") };
	//(constraint store) owlSubDataPropertyOf( ( ?int ), ( ?int ) ), indexes: { <0>, <1>, <0,1> }, persistent
public:
	struct owlSubDataPropertyOf {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<1>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlSubDataPropertyOf_constraint_store && _space->owlSubDataPropertyOf_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlSubDataPropertyOf(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlSubDataPropertyOf::Constraint_store_t > owlSubDataPropertyOf_constraint_store{ chr::make_shared< typename owlSubDataPropertyOf::Constraint_store_t >("owlSubDataPropertyOf") };
	//(constraint store) owlSubObjectPropertyOf( ( ?int ), ( ?int ) ), indexes: { <0>, <1>, <0,1> }, persistent
public:
	struct owlSubObjectPropertyOf {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<1>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlSubObjectPropertyOf_constraint_store && _space->owlSubObjectPropertyOf_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlSubObjectPropertyOf(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlSubObjectPropertyOf::Constraint_store_t > owlSubObjectPropertyOf_constraint_store{ chr::make_shared< typename owlSubObjectPropertyOf::Constraint_store_t >("owlSubObjectPropertyOf") };
	//(constraint store) owlEquivalentDataProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct owlEquivalentDataProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlEquivalentDataProperty_constraint_store && _space->owlEquivalentDataProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlEquivalentDataProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlEquivalentDataProperty::Constraint_store_t > owlEquivalentDataProperty_constraint_store{ chr::make_shared< typename owlEquivalentDataProperty::Constraint_store_t >("owlEquivalentDataProperty") };
	//(constraint store) owlEquivalentObjectProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct owlEquivalentObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlEquivalentObjectProperty_constraint_store && _space->owlEquivalentObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlEquivalentObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlEquivalentObjectProperty::Constraint_store_t > owlEquivalentObjectProperty_constraint_store{ chr::make_shared< typename owlEquivalentObjectProperty::Constraint_store_t >("owlEquivalentObjectProperty") };
	//(constraint store) owlObjectPropertyDomain( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1>, <1> }, persistent
public:
	struct owlObjectPropertyDomain {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1>, chr::LNS::Index<1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlObjectPropertyDomain_constraint_store && _space->owlObjectPropertyDomain_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlObjectPropertyDomain(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlObjectPropertyDomain::Constraint_store_t > owlObjectPropertyDomain_constraint_store{ chr::make_shared< typename owlObjectPropertyDomain::Constraint_store_t >("owlObjectPropertyDomain") };
	//(constraint store) owlDataPropertyDomain( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1> }, persistent
public:
	struct owlDataPropertyDomain {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDataPropertyDomain_constraint_store && _space->owlDataPropertyDomain_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDataPropertyDomain(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDataPropertyDomain::Constraint_store_t > owlDataPropertyDomain_constraint_store{ chr::make_shared< typename owlDataPropertyDomain::Constraint_store_t >("owlDataPropertyDomain") };
	//(constraint store) owlObjectPropertyRange( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1>, <1> }, persistent
public:
	struct owlObjectPropertyRange {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1>, chr::LNS::Index<1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlObjectPropertyRange_constraint_store && _space->owlObjectPropertyRange_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlObjectPropertyRange(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlObjectPropertyRange::Constraint_store_t > owlObjectPropertyRange_constraint_store{ chr::make_shared< typename owlObjectPropertyRange::Constraint_store_t >("owlObjectPropertyRange") };
	//(constraint store) owlClassAssertion( ( ?int ), ( ?int ), ( +bool ) ), indexes: { <0,2>, <1,2>, <0,1,2>, <2>, <0> }, persistent
public:
	struct owlClassAssertion {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< bool > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,2>, chr::LNS::Index<1,2>, chr::LNS::Index<0,1,2>, chr::LNS::Index<2>, chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlClassAssertion_constraint_store && _space->owlClassAssertion_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlClassAssertion(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlClassAssertion::Constraint_store_t > owlClassAssertion_constraint_store{ chr::make_shared< typename owlClassAssertion::Constraint_store_t >("owlClassAssertion") };
	//(constraint store) owlDisjointClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct owlDisjointClass {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDisjointClass_constraint_store && _space->owlDisjointClass_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDisjointClass(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDisjointClass::Constraint_store_t > owlDisjointClass_constraint_store{ chr::make_shared< typename owlDisjointClass::Constraint_store_t >("owlDisjointClass") };
	//(constraint store) owlNegativeObjectAssertion( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0,1,2> }, persistent
public:
	struct owlNegativeObjectAssertion {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlNegativeObjectAssertion_constraint_store && _space->owlNegativeObjectAssertion_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlNegativeObjectAssertion(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlNegativeObjectAssertion::Constraint_store_t > owlNegativeObjectAssertion_constraint_store{ chr::make_shared< typename owlNegativeObjectAssertion::Constraint_store_t >("owlNegativeObjectAssertion") };
	//(constraint store) owlObjectPropertyAssertion( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0,1>, <2>, <0,1,2>, <1>, <1,2>, <0,2>, <0> }, persistent
public:
	struct owlObjectPropertyAssertion {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<2>, chr::LNS::Index<0,1,2>, chr::LNS::Index<1>, chr::LNS::Index<1,2>, chr::LNS::Index<0,2>, chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlObjectPropertyAssertion_constraint_store && _space->owlObjectPropertyAssertion_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlObjectPropertyAssertion(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlObjectPropertyAssertion::Constraint_store_t > owlObjectPropertyAssertion_constraint_store{ chr::make_shared< typename owlObjectPropertyAssertion::Constraint_store_t >("owlObjectPropertyAssertion") };
	//(constraint store) owlSameIndividual( ( ?int ), ( ?int ) ), indexes: { <0>, <0,1>, <1> }, persistent
public:
	struct owlSameIndividual {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1>, chr::LNS::Index<1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlSameIndividual_constraint_store && _space->owlSameIndividual_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlSameIndividual(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlSameIndividual::Constraint_store_t > owlSameIndividual_constraint_store{ chr::make_shared< typename owlSameIndividual::Constraint_store_t >("owlSameIndividual") };
	//(constraint store) owlDifferentIndividual( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct owlDifferentIndividual {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDifferentIndividual_constraint_store && _space->owlDifferentIndividual_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDifferentIndividual(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDifferentIndividual::Constraint_store_t > owlDifferentIndividual_constraint_store{ chr::make_shared< typename owlDifferentIndividual::Constraint_store_t >("owlDifferentIndividual") };
	//(constraint store) owlInverseObjectProperty( ( ?int ), ( ?int ) ), indexes: { <0,1>, <0> }, persistent
public:
	struct owlInverseObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlInverseObjectProperty_constraint_store && _space->owlInverseObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlInverseObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlInverseObjectProperty::Constraint_store_t > owlInverseObjectProperty_constraint_store{ chr::make_shared< typename owlInverseObjectProperty::Constraint_store_t >("owlInverseObjectProperty") };
	//(constraint store) owlSymmetricObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlSymmetricObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlSymmetricObjectProperty_constraint_store && _space->owlSymmetricObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlSymmetricObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlSymmetricObjectProperty::Constraint_store_t > owlSymmetricObjectProperty_constraint_store{ chr::make_shared< typename owlSymmetricObjectProperty::Constraint_store_t >("owlSymmetricObjectProperty") };
	//(constraint store) owlAsymmetricObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlAsymmetricObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlAsymmetricObjectProperty_constraint_store && _space->owlAsymmetricObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlAsymmetricObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlAsymmetricObjectProperty::Constraint_store_t > owlAsymmetricObjectProperty_constraint_store{ chr::make_shared< typename owlAsymmetricObjectProperty::Constraint_store_t >("owlAsymmetricObjectProperty") };
	//(constraint store) owlDisjointObjectProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct owlDisjointObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDisjointObjectProperty_constraint_store && _space->owlDisjointObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDisjointObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDisjointObjectProperty::Constraint_store_t > owlDisjointObjectProperty_constraint_store{ chr::make_shared< typename owlDisjointObjectProperty::Constraint_store_t >("owlDisjointObjectProperty") };
	//(constraint store) owlDisjointDataProperty( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct owlDisjointDataProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDisjointDataProperty_constraint_store && _space->owlDisjointDataProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDisjointDataProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDisjointDataProperty::Constraint_store_t > owlDisjointDataProperty_constraint_store{ chr::make_shared< typename owlDisjointDataProperty::Constraint_store_t >("owlDisjointDataProperty") };
	//(constraint store) owlReflexiveObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlReflexiveObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlReflexiveObjectProperty_constraint_store && _space->owlReflexiveObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlReflexiveObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlReflexiveObjectProperty::Constraint_store_t > owlReflexiveObjectProperty_constraint_store{ chr::make_shared< typename owlReflexiveObjectProperty::Constraint_store_t >("owlReflexiveObjectProperty") };
	//(constraint store) owlIrreflexiveObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlIrreflexiveObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlIrreflexiveObjectProperty_constraint_store && _space->owlIrreflexiveObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlIrreflexiveObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlIrreflexiveObjectProperty::Constraint_store_t > owlIrreflexiveObjectProperty_constraint_store{ chr::make_shared< typename owlIrreflexiveObjectProperty::Constraint_store_t >("owlIrreflexiveObjectProperty") };
	//(constraint store) owlFunctionalObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlFunctionalObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlFunctionalObjectProperty_constraint_store && _space->owlFunctionalObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlFunctionalObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlFunctionalObjectProperty::Constraint_store_t > owlFunctionalObjectProperty_constraint_store{ chr::make_shared< typename owlFunctionalObjectProperty::Constraint_store_t >("owlFunctionalObjectProperty") };
	//(constraint store) owlFunctionalDataProperty( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlFunctionalDataProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlFunctionalDataProperty_constraint_store && _space->owlFunctionalDataProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlFunctionalDataProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlFunctionalDataProperty::Constraint_store_t > owlFunctionalDataProperty_constraint_store{ chr::make_shared< typename owlFunctionalDataProperty::Constraint_store_t >("owlFunctionalDataProperty") };
	//(constraint store) owlInverseFunctionalObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlInverseFunctionalObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlInverseFunctionalObjectProperty_constraint_store && _space->owlInverseFunctionalObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlInverseFunctionalObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlInverseFunctionalObjectProperty::Constraint_store_t > owlInverseFunctionalObjectProperty_constraint_store{ chr::make_shared< typename owlInverseFunctionalObjectProperty::Constraint_store_t >("owlInverseFunctionalObjectProperty") };
	//(constraint store) owlTransitiveObjectProperty( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct owlTransitiveObjectProperty {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlTransitiveObjectProperty_constraint_store && _space->owlTransitiveObjectProperty_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlTransitiveObjectProperty(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlTransitiveObjectProperty::Constraint_store_t > owlTransitiveObjectProperty_constraint_store{ chr::make_shared< typename owlTransitiveObjectProperty::Constraint_store_t >("owlTransitiveObjectProperty") };
	//(constraint store) owlDataPropertyAssertion( ( ?int ), ( ?int ), ( +Value ) ), indexes: { <0>, <0,1>, <0,1,2>, <0,2>, <1,2>, <1>, <2> }, persistent
public:
	struct owlDataPropertyAssertion {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< Value > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1>, chr::LNS::Index<0,1,2>, chr::LNS::Index<0,2>, chr::LNS::Index<1,2>, chr::LNS::Index<1>, chr::LNS::Index<2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDataPropertyAssertion_constraint_store && _space->owlDataPropertyAssertion_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDataPropertyAssertion(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDataPropertyAssertion::Constraint_store_t > owlDataPropertyAssertion_constraint_store{ chr::make_shared< typename owlDataPropertyAssertion::Constraint_store_t >("owlDataPropertyAssertion") };
	//(constraint store) owlNegativeDataAssertion( ( ?int ), ( ?int ), ( +Value ) ), indexes: { <0,1,2> }, persistent
public:
	struct owlNegativeDataAssertion {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< Value > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlNegativeDataAssertion_constraint_store && _space->owlNegativeDataAssertion_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlNegativeDataAssertion(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlNegativeDataAssertion::Constraint_store_t > owlNegativeDataAssertion_constraint_store{ chr::make_shared< typename owlNegativeDataAssertion::Constraint_store_t >("owlNegativeDataAssertion") };
	//(constraint store) owlDataPropertyRange( ( ?int ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0>, <0,1> }, persistent
public:
	struct owlDataPropertyRange {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< std :: shared_ptr< AnySimpleType > > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDataPropertyRange_constraint_store && _space->owlDataPropertyRange_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDataPropertyRange(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDataPropertyRange::Constraint_store_t > owlDataPropertyRange_constraint_store{ chr::make_shared< typename owlDataPropertyRange::Constraint_store_t >("owlDataPropertyRange") };
	//(constraint store) owlUnionClass( ( ?int ), ( ?int ) ), indexes: { <1>, <0,1> }, persistent
public:
	struct owlUnionClass {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<1>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlUnionClass_constraint_store && _space->owlUnionClass_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlUnionClass(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlUnionClass::Constraint_store_t > owlUnionClass_constraint_store{ chr::make_shared< typename owlUnionClass::Constraint_store_t >("owlUnionClass") };
	//(constraint store) owlUnionOf( ( ?int ), ( +LogicalVarSet ) ), indexes: { <0,1>, <1> }, persistent
public:
	struct owlUnionOf {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< LogicalVarSet > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlUnionOf_constraint_store && _space->owlUnionOf_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlUnionOf(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlUnionOf::Constraint_store_t > owlUnionOf_constraint_store{ chr::make_shared< typename owlUnionOf::Constraint_store_t >("owlUnionOf") };
	//(constraint store) owlUnionOfLoop( ( ?int ), ( +LogicalVarSetIterator ), ( +LogicalVarSetIterator ) ), persistent
public:
	struct owlUnionOfLoop {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< LogicalVarSetIterator >, chr::Logical_var_ground< LogicalVarSetIterator > >;
	};
	//(constraint store) owlIntersectionOf( ( ?int ), ( +LogicalVarSet ) ), indexes: { <0,1> }, persistent
public:
	struct owlIntersectionOf {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< LogicalVarSet > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlIntersectionOf_constraint_store && _space->owlIntersectionOf_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlIntersectionOf(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlIntersectionOf::Constraint_store_t > owlIntersectionOf_constraint_store{ chr::make_shared< typename owlIntersectionOf::Constraint_store_t >("owlIntersectionOf") };
	//(constraint store) owlIntersectionClass( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,2>, <0,1,2>, <1,2>, <1>, <0> }, persistent
public:
	struct owlIntersectionClass {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,2>, chr::LNS::Index<0,1,2>, chr::LNS::Index<1,2>, chr::LNS::Index<1>, chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlIntersectionClass_constraint_store && _space->owlIntersectionClass_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlIntersectionClass(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlIntersectionClass::Constraint_store_t > owlIntersectionClass_constraint_store{ chr::make_shared< typename owlIntersectionClass::Constraint_store_t >("owlIntersectionClass") };
	//(constraint store) owlIntersectionOfLoop( ( ?int ), ( +LogicalVarSetIterator ), ( +LogicalVarSetIterator ), ( +int ) ), indexes: { <0,3>, <0,1,2,3> }, persistent
public:
	struct owlIntersectionOfLoop {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< LogicalVarSetIterator >, chr::Logical_var_ground< LogicalVarSetIterator >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,3>, chr::LNS::Index<0,1,2,3> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlIntersectionOfLoop_constraint_store && _space->owlIntersectionOfLoop_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlIntersectionOfLoop(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlIntersectionOfLoop::Constraint_store_t > owlIntersectionOfLoop_constraint_store{ chr::make_shared< typename owlIntersectionOfLoop::Constraint_store_t >("owlIntersectionOfLoop") };
	//(constraint store) intersectionSubclassCheck( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1,2>, <0,2> }, persistent
public:
	struct intersectionSubclassCheck {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1,2>, chr::LNS::Index<0,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->intersectionSubclassCheck_constraint_store && _space->intersectionSubclassCheck_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_intersectionSubclassCheck(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename intersectionSubclassCheck::Constraint_store_t > intersectionSubclassCheck_constraint_store{ chr::make_shared< typename intersectionSubclassCheck::Constraint_store_t >("intersectionSubclassCheck") };
	//(constraint store) owlCandidatsIntersection( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1,2>, <1,2> }, persistent
public:
	struct owlCandidatsIntersection {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1,2>, chr::LNS::Index<1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlCandidatsIntersection_constraint_store && _space->owlCandidatsIntersection_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlCandidatsIntersection(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlCandidatsIntersection::Constraint_store_t > owlCandidatsIntersection_constraint_store{ chr::make_shared< typename owlCandidatsIntersection::Constraint_store_t >("owlCandidatsIntersection") };
	//(constraint store) owlObjectAllValuesFrom( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0,1,2> }, persistent
public:
	struct owlObjectAllValuesFrom {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlObjectAllValuesFrom_constraint_store && _space->owlObjectAllValuesFrom_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlObjectAllValuesFrom(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlObjectAllValuesFrom::Constraint_store_t > owlObjectAllValuesFrom_constraint_store{ chr::make_shared< typename owlObjectAllValuesFrom::Constraint_store_t >("owlObjectAllValuesFrom") };
	//(constraint store) owlDataAllValuesFrom( ( ?int ), ( ?int ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0,1,2> }, persistent
public:
	struct owlDataAllValuesFrom {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< std :: shared_ptr< AnySimpleType > > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDataAllValuesFrom_constraint_store && _space->owlDataAllValuesFrom_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDataAllValuesFrom(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDataAllValuesFrom::Constraint_store_t > owlDataAllValuesFrom_constraint_store{ chr::make_shared< typename owlDataAllValuesFrom::Constraint_store_t >("owlDataAllValuesFrom") };
	//(constraint store) owlObjectSomeValuesFrom( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <2>, <0>, <1,2>, <0,1,2> }, persistent
public:
	struct owlObjectSomeValuesFrom {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<2>, chr::LNS::Index<0>, chr::LNS::Index<1,2>, chr::LNS::Index<0,1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlObjectSomeValuesFrom_constraint_store && _space->owlObjectSomeValuesFrom_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlObjectSomeValuesFrom(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlObjectSomeValuesFrom::Constraint_store_t > owlObjectSomeValuesFrom_constraint_store{ chr::make_shared< typename owlObjectSomeValuesFrom::Constraint_store_t >("owlObjectSomeValuesFrom") };
	//(constraint store) owlDataSomeValuesFrom( ( ?int ), ( ?int ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0>, <1>, <0,1,2> }, persistent
public:
	struct owlDataSomeValuesFrom {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< std :: shared_ptr< AnySimpleType > > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<1>, chr::LNS::Index<0,1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDataSomeValuesFrom_constraint_store && _space->owlDataSomeValuesFrom_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDataSomeValuesFrom(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDataSomeValuesFrom::Constraint_store_t > owlDataSomeValuesFrom_constraint_store{ chr::make_shared< typename owlDataSomeValuesFrom::Constraint_store_t >("owlDataSomeValuesFrom") };
	//(constraint store) owlDataValue( ( +Value ), ( +( std :: string ) ), ( +( std :: shared_ptr< AnySimpleType > ) ) ), indexes: { <0,1>, <0>, <1>, <0,1,2> }, persistent
public:
	struct owlDataValue {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< Value >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: shared_ptr< AnySimpleType > > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<0>, chr::LNS::Index<1>, chr::LNS::Index<0,1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDataValue_constraint_store && _space->owlDataValue_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDataValue(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDataValue::Constraint_store_t > owlDataValue_constraint_store{ chr::make_shared< typename owlDataValue::Constraint_store_t >("owlDataValue") };
	//(constraint store) owlComplementOf( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct owlComplementOf {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlComplementOf_constraint_store && _space->owlComplementOf_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlComplementOf(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlComplementOf::Constraint_store_t > owlComplementOf_constraint_store{ chr::make_shared< typename owlComplementOf::Constraint_store_t >("owlComplementOf") };
	//(constraint store) owlObjectMaxCardinality( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,2>, <0,1,2>, <1,2> }, persistent
public:
	struct owlObjectMaxCardinality {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,2>, chr::LNS::Index<0,1,2>, chr::LNS::Index<1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlObjectMaxCardinality_constraint_store && _space->owlObjectMaxCardinality_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlObjectMaxCardinality(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlObjectMaxCardinality::Constraint_store_t > owlObjectMaxCardinality_constraint_store{ chr::make_shared< typename owlObjectMaxCardinality::Constraint_store_t >("owlObjectMaxCardinality") };
	//(constraint store) owlDataMaxCardinality( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,2>, <0,1,2>, <1,2> }, persistent
public:
	struct owlDataMaxCardinality {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,2>, chr::LNS::Index<0,1,2>, chr::LNS::Index<1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlDataMaxCardinality_constraint_store && _space->owlDataMaxCardinality_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlDataMaxCardinality(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlDataMaxCardinality::Constraint_store_t > owlDataMaxCardinality_constraint_store{ chr::make_shared< typename owlDataMaxCardinality::Constraint_store_t >("owlDataMaxCardinality") };
	//(constraint store) owlHasValueObject( ( ?int ), ( ?int ), ( ?int ) ), indexes: { <0>, <2>, <0,1,2>, <0,1>, <1,2> }, persistent
public:
	struct owlHasValueObject {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<2>, chr::LNS::Index<0,1,2>, chr::LNS::Index<0,1>, chr::LNS::Index<1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlHasValueObject_constraint_store && _space->owlHasValueObject_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlHasValueObject(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlHasValueObject::Constraint_store_t > owlHasValueObject_constraint_store{ chr::make_shared< typename owlHasValueObject::Constraint_store_t >("owlHasValueObject") };
	//(constraint store) owlOneOf( ( ?int ), ( +LogicalVarSet ) ), indexes: { <0,1> }, persistent
public:
	struct owlOneOf {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< LogicalVarSet > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlOneOf_constraint_store && _space->owlOneOf_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlOneOf(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlOneOf::Constraint_store_t > owlOneOf_constraint_store{ chr::make_shared< typename owlOneOf::Constraint_store_t >("owlOneOf") };
	//(constraint store) owlOneOfLoop( ( ?int ), ( +LogicalVarSetIterator ), ( +LogicalVarSetIterator ) ), indexes: { <0,1,2> }, persistent
public:
	struct owlOneOfLoop {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< LogicalVarSetIterator >, chr::Logical_var_ground< LogicalVarSetIterator > >;
	};
	//(constraint store) owlObjectPropertyChain( ( ?int ), ( ?int ), ( +int ), ( +int ) ), indexes: { <0,3>, <1,2>, <1> }, persistent
public:
	struct owlObjectPropertyChain {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,3>, chr::LNS::Index<1,2>, chr::LNS::Index<1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlObjectPropertyChain_constraint_store && _space->owlObjectPropertyChain_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlObjectPropertyChain(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlObjectPropertyChain::Constraint_store_t > owlObjectPropertyChain_constraint_store{ chr::make_shared< typename owlObjectPropertyChain::Constraint_store_t >("owlObjectPropertyChain") };
	//(constraint store) constructPropertyChain( ( ?int ), ( +int ), ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1,2,3,4>, <0,3,4>, <0,4> }, persistent
public:
	struct constructPropertyChain {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1,2,3,4>, chr::LNS::Index<0,3,4>, chr::LNS::Index<0,4> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->constructPropertyChain_constraint_store && _space->constructPropertyChain_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_constructPropertyChain(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename constructPropertyChain::Constraint_store_t > constructPropertyChain_constraint_store{ chr::make_shared< typename constructPropertyChain::Constraint_store_t >("constructPropertyChain") };
	//(constraint store) owlHasKey( ( ?int ), ( ?int ), ( +int ), ( +int ) ), indexes: { <0,2>, <0,1,2,3>, <0,2,3> }, persistent
public:
	struct owlHasKey {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,2>, chr::LNS::Index<0,1,2,3>, chr::LNS::Index<0,2,3> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlHasKey_constraint_store && _space->owlHasKey_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlHasKey(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlHasKey::Constraint_store_t > owlHasKey_constraint_store{ chr::make_shared< typename owlHasKey::Constraint_store_t >("owlHasKey") };
	//(constraint store) owlHasKeyCheck( ( ?int ), ( ?int ), ( ?int ), ( +int ), ( +int ) ), indexes: { <1,2>, <0,3,4>, <0,1,2,3,4> }, persistent
public:
	struct owlHasKeyCheck {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<1,2>, chr::LNS::Index<0,3,4>, chr::LNS::Index<0,1,2,3,4> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->owlHasKeyCheck_constraint_store && _space->owlHasKeyCheck_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_owlHasKeyCheck(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename owlHasKeyCheck::Constraint_store_t > owlHasKeyCheck_constraint_store{ chr::make_shared< typename owlHasKeyCheck::Constraint_store_t >("owlHasKeyCheck") };
	//(constraint store) querySuperClassOfUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
public:
	struct querySuperClassOfUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->querySuperClassOfUri_constraint_store && _space->querySuperClassOfUri_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_querySuperClassOfUri(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename querySuperClassOfUri::Constraint_store_t > querySuperClassOfUri_constraint_store{ chr::make_shared< typename querySuperClassOfUri::Constraint_store_t >("querySuperClassOfUri") };
	//(constraint store) querySuperClassOfClassUri( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
public:
	struct querySuperClassOfClassUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->querySuperClassOfClassUri_constraint_store && _space->querySuperClassOfClassUri_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_querySuperClassOfClassUri(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename querySuperClassOfClassUri::Constraint_store_t > querySuperClassOfClassUri_constraint_store{ chr::make_shared< typename querySuperClassOfClassUri::Constraint_store_t >("querySuperClassOfClassUri") };
	//(constraint store) querySubClassOfUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
public:
	struct querySubClassOfUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->querySubClassOfUri_constraint_store && _space->querySubClassOfUri_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_querySubClassOfUri(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename querySubClassOfUri::Constraint_store_t > querySubClassOfUri_constraint_store{ chr::make_shared< typename querySubClassOfUri::Constraint_store_t >("querySubClassOfUri") };
	//(constraint store) querySubClassOfClassUri( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
public:
	struct querySubClassOfClassUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->querySubClassOfClassUri_constraint_store && _space->querySubClassOfClassUri_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_querySubClassOfClassUri(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename querySubClassOfClassUri::Constraint_store_t > querySubClassOfClassUri_constraint_store{ chr::make_shared< typename querySubClassOfClassUri::Constraint_store_t >("querySubClassOfClassUri") };
	//(constraint store) querySuperClassOf( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct querySuperClassOf {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->querySuperClassOf_constraint_store && _space->querySuperClassOf_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_querySuperClassOf(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename querySuperClassOf::Constraint_store_t > querySuperClassOf_constraint_store{ chr::make_shared< typename querySuperClassOf::Constraint_store_t >("querySuperClassOf") };
	//(constraint store) querySuperClassOfReal( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct querySuperClassOfReal {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->querySuperClassOfReal_constraint_store && _space->querySuperClassOfReal_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_querySuperClassOfReal(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename querySuperClassOfReal::Constraint_store_t > querySuperClassOfReal_constraint_store{ chr::make_shared< typename querySuperClassOfReal::Constraint_store_t >("querySuperClassOfReal") };
	//(constraint store) querySubClassOf( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct querySubClassOf {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->querySubClassOf_constraint_store && _space->querySubClassOf_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_querySubClassOf(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename querySubClassOf::Constraint_store_t > querySubClassOf_constraint_store{ chr::make_shared< typename querySubClassOf::Constraint_store_t >("querySubClassOf") };
	//(constraint store) querySubClassOfClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct querySubClassOfClass {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
	};
	//(constraint store) querySuperClassOfClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct querySuperClassOfClass {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
	};
	//(constraint store) queryClassification( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct queryClassification {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryClassification_constraint_store && _space->queryClassification_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryClassification(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryClassification::Constraint_store_t > queryClassification_constraint_store{ chr::make_shared< typename queryClassification::Constraint_store_t >("queryClassification") };
	//(constraint store) queryClassificationReal( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct queryClassificationReal {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryClassificationReal_constraint_store && _space->queryClassificationReal_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryClassificationReal(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryClassificationReal::Constraint_store_t > queryClassificationReal_constraint_store{ chr::make_shared< typename queryClassificationReal::Constraint_store_t >("queryClassificationReal") };
	//(constraint store) queryClassificationUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
public:
	struct queryClassificationUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryClassificationUri_constraint_store && _space->queryClassificationUri_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryClassificationUri(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryClassificationUri::Constraint_store_t > queryClassificationUri_constraint_store{ chr::make_shared< typename queryClassificationUri::Constraint_store_t >("queryClassificationUri") };
	//(constraint store) queryClassificationTemp( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct queryClassificationTemp {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryClassificationTemp_constraint_store && _space->queryClassificationTemp_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryClassificationTemp(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryClassificationTemp::Constraint_store_t > queryClassificationTemp_constraint_store{ chr::make_shared< typename queryClassificationTemp::Constraint_store_t >("queryClassificationTemp") };
	//(constraint store) queryClassificationTempUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
public:
	struct queryClassificationTempUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryClassificationTempUri_constraint_store && _space->queryClassificationTempUri_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryClassificationTempUri(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryClassificationTempUri::Constraint_store_t > queryClassificationTempUri_constraint_store{ chr::make_shared< typename queryClassificationTempUri::Constraint_store_t >("queryClassificationTempUri") };
	//(constraint store) queryInstanceURI( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
public:
	struct queryInstanceURI {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryInstanceURI_constraint_store && _space->queryInstanceURI_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryInstanceURI(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryInstanceURI::Constraint_store_t > queryInstanceURI_constraint_store{ chr::make_shared< typename queryInstanceURI::Constraint_store_t >("queryInstanceURI") };
	//(constraint store) queryInstance( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct queryInstance {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
	};
	//(constraint store) queryInstancesURI( ( +( std :: string ) ) ), indexes: { <0> }, persistent
public:
	struct queryInstancesURI {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string > >;
	};
	//(constraint store) queryInstances( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
public:
	struct queryInstances {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryInstances_constraint_store && _space->queryInstances_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryInstances(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryInstances::Constraint_store_t > queryInstances_constraint_store{ chr::make_shared< typename queryInstances::Constraint_store_t >("queryInstances") };
	//(constraint store) queryObjAssertionUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
public:
	struct queryObjAssertionUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string > >;
	};
	//(constraint store) queryObjAssertion( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
public:
	struct queryObjAssertion {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryObjAssertion_constraint_store && _space->queryObjAssertion_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryObjAssertion(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryObjAssertion::Constraint_store_t > queryObjAssertion_constraint_store{ chr::make_shared< typename queryObjAssertion::Constraint_store_t >("queryObjAssertion") };
	//(constraint store) querySubjectByObjectUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
public:
	struct querySubjectByObjectUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string > >;
	};
	//(constraint store) querySubjectByObject( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
public:
	struct querySubjectByObject {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->querySubjectByObject_constraint_store && _space->querySubjectByObject_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_querySubjectByObject(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename querySubjectByObject::Constraint_store_t > querySubjectByObject_constraint_store{ chr::make_shared< typename querySubjectByObject::Constraint_store_t >("querySubjectByObject") };
	//(constraint store) queryDataAssertionUri( ( +( std :: string ) ) ), indexes: { <0> }, persistent
public:
	struct queryDataAssertionUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string > >;
	};
	//(constraint store) queryDataAssertion( ( ?int ), ( +int ) ), indexes: { <0>, <0,1> }, persistent
public:
	struct queryDataAssertion {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryDataAssertion_constraint_store && _space->queryDataAssertion_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryDataAssertion(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryDataAssertion::Constraint_store_t > queryDataAssertion_constraint_store{ chr::make_shared< typename queryDataAssertion::Constraint_store_t >("queryDataAssertion") };
	//(constraint store) queryEngineeringStudentsUri( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ) ), persistent
public:
	struct queryEngineeringStudentsUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string > >;
	};
	//(constraint store) queryEngineeringStudents( ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( +int ) ), indexes: { <0>, <0,1>, <0,2>, <0,3,4> }, persistent
public:
	struct queryEngineeringStudents {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1>, chr::LNS::Index<0,2>, chr::LNS::Index<0,3,4> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryEngineeringStudents_constraint_store && _space->queryEngineeringStudents_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryEngineeringStudents(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryEngineeringStudents::Constraint_store_t > queryEngineeringStudents_constraint_store{ chr::make_shared< typename queryEngineeringStudents::Constraint_store_t >("queryEngineeringStudents") };
	//(constraint store) queryComplexStudentsUri( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ) ), persistent
public:
	struct queryComplexStudentsUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string > >;
	};
	//(constraint store) queryComplexStudents( ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1>, <0,1,2>, <0,1,3>, <0,1,4> }, persistent
public:
	struct queryComplexStudents {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<0,1,2>, chr::LNS::Index<0,1,3>, chr::LNS::Index<0,1,4> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryComplexStudents_constraint_store && _space->queryComplexStudents_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryComplexStudents(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryComplexStudents::Constraint_store_t > queryComplexStudents_constraint_store{ chr::make_shared< typename queryComplexStudents::Constraint_store_t >("queryComplexStudents") };
	//(constraint store) queryObjAssertionSubjectUri( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
public:
	struct queryObjAssertionSubjectUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string > >;
	};
	//(constraint store) queryObjAssertionSubject( ( ?int ), ( ?int ), ( +int ) ), indexes: { <0,1>, <0,1,2> }, persistent
public:
	struct queryObjAssertionSubject {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1>, chr::LNS::Index<0,1,2> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryObjAssertionSubject_constraint_store && _space->queryObjAssertionSubject_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryObjAssertionSubject(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryObjAssertionSubject::Constraint_store_t > queryObjAssertionSubject_constraint_store{ chr::make_shared< typename queryObjAssertionSubject::Constraint_store_t >("queryObjAssertionSubject") };
	//(constraint store) queryObjAssertionClassUri( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct queryObjAssertionClassUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryObjAssertionClassUri_constraint_store && _space->queryObjAssertionClassUri_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryObjAssertionClassUri(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryObjAssertionClassUri::Constraint_store_t > queryObjAssertionClassUri_constraint_store{ chr::make_shared< typename queryObjAssertionClassUri::Constraint_store_t >("queryObjAssertionClassUri") };
	//(constraint store) queryObjAssertionClass( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct queryObjAssertionClass {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryObjAssertionClass_constraint_store && _space->queryObjAssertionClass_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryObjAssertionClass(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryObjAssertionClass::Constraint_store_t > queryObjAssertionClass_constraint_store{ chr::make_shared< typename queryObjAssertionClass::Constraint_store_t >("queryObjAssertionClass") };
	//(constraint store) queryEquivalentClass( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct queryEquivalentClass {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryEquivalentClass_constraint_store && _space->queryEquivalentClass_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryEquivalentClass(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryEquivalentClass::Constraint_store_t > queryEquivalentClass_constraint_store{ chr::make_shared< typename queryEquivalentClass::Constraint_store_t >("queryEquivalentClass") };
	//(constraint store) queryEquivalentClassReal( ( ?int ), ( ?int ) ), indexes: { <0,1> }, persistent
public:
	struct queryEquivalentClassReal {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryEquivalentClassReal_constraint_store && _space->queryEquivalentClassReal_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryEquivalentClassReal(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryEquivalentClassReal::Constraint_store_t > queryEquivalentClassReal_constraint_store{ chr::make_shared< typename queryEquivalentClassReal::Constraint_store_t >("queryEquivalentClassReal") };
	//(constraint store) res( ( +( std :: string ) ) ), indexes: { <0> }, persistent
public:
	struct res {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->res_constraint_store && _space->res_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_res(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename res::Constraint_store_t > res_constraint_store{ chr::make_shared< typename res::Constraint_store_t >("res") };
	//(constraint store) resultRealisation( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0,1> }, persistent
public:
	struct resultRealisation {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->resultRealisation_constraint_store && _space->resultRealisation_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_resultRealisation(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename resultRealisation::Constraint_store_t > resultRealisation_constraint_store{ chr::make_shared< typename resultRealisation::Constraint_store_t >("resultRealisation") };
	//(constraint store) classification(  ), persistent
public:
	struct classification {
		using Type = typename std::tuple< unsigned long int >;
		using Constraint_store_t = typename chr::Constraint_store_simple< Type, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->classification_constraint_store && _space->classification_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_classification(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename classification::Constraint_store_t > classification_constraint_store{ chr::make_shared< typename classification::Constraint_store_t >("classification") };
	//(constraint store) resultClassification( ( +( std :: string ) ), ( +( std :: string ) ) ), indexes: { <0>, <0,1> }, persistent
public:
	struct resultClassification {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->resultClassification_constraint_store && _space->resultClassification_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_resultClassification(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename resultClassification::Constraint_store_t > resultClassification_constraint_store{ chr::make_shared< typename resultClassification::Constraint_store_t >("resultClassification") };
	//(constraint store) queryFullUri( ( ?int ) ), indexes: { <0> }, persistent
public:
	struct queryFullUri {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryFullUri_constraint_store && _space->queryFullUri_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryFullUri(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryFullUri::Constraint_store_t > queryFullUri_constraint_store{ chr::make_shared< typename queryFullUri::Constraint_store_t >("queryFullUri") };
	//(constraint store) logicalName( ( +( std :: string ) ), ( ?int ) ), indexes: { <0>, <1>, <0,1> }, persistent
public:
	struct logicalName {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0>, chr::LNS::Index<1>, chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->logicalName_constraint_store && _space->logicalName_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_logicalName(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename logicalName::Constraint_store_t > logicalName_constraint_store{ chr::make_shared< typename logicalName::Constraint_store_t >("logicalName") };
	//(constraint store) realisation(  ), persistent
public:
	struct realisation {
		using Type = typename std::tuple< unsigned long int >;
		using Constraint_store_t = typename chr::Constraint_store_simple< Type, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->realisation_constraint_store && _space->realisation_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_realisation(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename realisation::Constraint_store_t > realisation_constraint_store{ chr::make_shared< typename realisation::Constraint_store_t >("realisation") };
	//(constraint store) queryisMemberOf(  ), persistent
public:
	struct queryisMemberOf {
		using Type = typename std::tuple< unsigned long int >;
		using Constraint_store_t = typename chr::Constraint_store_simple< Type, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->queryisMemberOf_constraint_store && _space->queryisMemberOf_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_queryisMemberOf(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename queryisMemberOf::Constraint_store_t > queryisMemberOf_constraint_store{ chr::make_shared< typename queryisMemberOf::Constraint_store_t >("queryisMemberOf") };
	//(constraint store) ResultVec( ( +StringSet ), ( +int ) ), indexes: { <0,1> }, persistent
public:
	struct ResultVec {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< StringSet >, chr::Logical_var_ground< int > >;
		using Constraint_store_t = typename chr::Constraint_store_index< Type, std::tuple< chr::LNS::Index<0,1> >, false >;
		class Constraint_callback : public chr::Logical_var_imp_observer_constraint {
		public:
			Constraint_callback(OWL2* space, typename Constraint_store_t::iterator& it) : _space(space), _it( std::move(it) ) { assert((space != nullptr) && _it.alive()); _it.lock(); }
			Constraint_callback(const Constraint_callback&) =delete;
			void operator=(const Constraint_callback&) =delete;
			~Constraint_callback() { if (!_space.expired() && _space->ResultVec_constraint_store && _space->ResultVec_constraint_store->depth() >= chr::Backtrack::depth()) _it.unlock(); }
			unsigned char run() override {
				if (_space.expired()) return 0;
				if (!_it.alive()) return 0;
				auto& cc = const_cast< Type& >(*_it);
				if ( _space->do_ResultVec(cc, _it) == chr::ES_CHR::FAILURE ) { return 2; }
				return 1;
			}
		private:
			chr::Weak_obj< OWL2 > _space;
			typename Constraint_store_t::iterator _it;
		};
	};
private:
	chr::Shared_obj< typename ResultVec::Constraint_store_t > ResultVec_constraint_store{ chr::make_shared< typename ResultVec::Constraint_store_t >("ResultVec") };
	//(constraint store) queryInstancesWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
public:
	struct queryInstancesWithId {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< int > >;
	};
	//(constraint store) queryObjAssertionWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
public:
	struct queryObjAssertionWithId {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< int > >;
	};
	//(constraint store) queryDataAssertionWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
public:
	struct queryDataAssertionWithId {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< int > >;
	};
	//(constraint store) querySubjectByObjectWithId( ( +( std :: string ) ), ( +int ) ), indexes: { <0> }, persistent
public:
	struct querySubjectByObjectWithId {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< int > >;
	};
	//(constraint store) queryObjAssertionSubjectWithId( ( +( std :: string ) ), ( +( std :: string ) ), ( +int ) ), indexes: { <0>, <1> }, persistent
public:
	struct queryObjAssertionSubjectWithId {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< int > >;
	};
	//(constraint store) queryEngineeringStudentsWithId( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +int ) ), indexes: { <0>, <1>, <2>, <3>, <4> }, persistent
public:
	struct queryEngineeringStudentsWithId {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< int > >;
	};
	//(constraint store) queryComplexStudentsWithId( ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +( std :: string ) ), ( +int ) ), indexes: { <0>, <1>, <2>, <3>, <4> }, persistent
public:
	struct queryComplexStudentsWithId {
		using Type = typename std::tuple< unsigned long int, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< std :: string >, chr::Logical_var_ground< int > >;
	};
public:
	unsigned int _ref_use_count  = 0;///< Count of shared references
	unsigned int _ref_weak_count = 0;///< Count of weak references + (#shared != 0)
	OWL2() { }
	~OWL2() {
		owlPrefix_constraint_store.release();
		owlClass_constraint_store.release();
		owlObjectProperty_constraint_store.release();
		owlDataProperty_constraint_store.release();
		owlNamedIndividual_constraint_store.release();
		owlSubclassOf_constraint_store.release();
		owlEquivalentClass_constraint_store.release();
		owlSubDataPropertyOf_constraint_store.release();
		owlSubObjectPropertyOf_constraint_store.release();
		owlEquivalentDataProperty_constraint_store.release();
		owlEquivalentObjectProperty_constraint_store.release();
		owlObjectPropertyDomain_constraint_store.release();
		owlDataPropertyDomain_constraint_store.release();
		owlObjectPropertyRange_constraint_store.release();
		owlClassAssertion_constraint_store.release();
		owlDisjointClass_constraint_store.release();
		owlNegativeObjectAssertion_constraint_store.release();
		owlObjectPropertyAssertion_constraint_store.release();
		owlSameIndividual_constraint_store.release();
		owlDifferentIndividual_constraint_store.release();
		owlInverseObjectProperty_constraint_store.release();
		owlSymmetricObjectProperty_constraint_store.release();
		owlAsymmetricObjectProperty_constraint_store.release();
		owlDisjointObjectProperty_constraint_store.release();
		owlDisjointDataProperty_constraint_store.release();
		owlReflexiveObjectProperty_constraint_store.release();
		owlIrreflexiveObjectProperty_constraint_store.release();
		owlFunctionalObjectProperty_constraint_store.release();
		owlFunctionalDataProperty_constraint_store.release();
		owlInverseFunctionalObjectProperty_constraint_store.release();
		owlTransitiveObjectProperty_constraint_store.release();
		owlDataPropertyAssertion_constraint_store.release();
		owlNegativeDataAssertion_constraint_store.release();
		owlDataPropertyRange_constraint_store.release();
		owlUnionClass_constraint_store.release();
		owlUnionOf_constraint_store.release();
		owlIntersectionOf_constraint_store.release();
		owlIntersectionClass_constraint_store.release();
		owlIntersectionOfLoop_constraint_store.release();
		intersectionSubclassCheck_constraint_store.release();
		owlCandidatsIntersection_constraint_store.release();
		owlObjectAllValuesFrom_constraint_store.release();
		owlDataAllValuesFrom_constraint_store.release();
		owlObjectSomeValuesFrom_constraint_store.release();
		owlDataSomeValuesFrom_constraint_store.release();
		owlDataValue_constraint_store.release();
		owlComplementOf_constraint_store.release();
		owlObjectMaxCardinality_constraint_store.release();
		owlDataMaxCardinality_constraint_store.release();
		owlHasValueObject_constraint_store.release();
		owlOneOf_constraint_store.release();
		owlObjectPropertyChain_constraint_store.release();
		constructPropertyChain_constraint_store.release();
		owlHasKey_constraint_store.release();
		owlHasKeyCheck_constraint_store.release();
		querySuperClassOfUri_constraint_store.release();
		querySuperClassOfClassUri_constraint_store.release();
		querySubClassOfUri_constraint_store.release();
		querySubClassOfClassUri_constraint_store.release();
		querySuperClassOf_constraint_store.release();
		querySuperClassOfReal_constraint_store.release();
		querySubClassOf_constraint_store.release();
		queryClassification_constraint_store.release();
		queryClassificationReal_constraint_store.release();
		queryClassificationUri_constraint_store.release();
		queryClassificationTemp_constraint_store.release();
		queryClassificationTempUri_constraint_store.release();
		queryInstanceURI_constraint_store.release();
		queryInstances_constraint_store.release();
		queryObjAssertion_constraint_store.release();
		querySubjectByObject_constraint_store.release();
		queryDataAssertion_constraint_store.release();
		queryEngineeringStudents_constraint_store.release();
		queryComplexStudents_constraint_store.release();
		queryObjAssertionSubject_constraint_store.release();
		queryObjAssertionClassUri_constraint_store.release();
		queryObjAssertionClass_constraint_store.release();
		queryEquivalentClass_constraint_store.release();
		queryEquivalentClassReal_constraint_store.release();
		res_constraint_store.release();
		resultRealisation_constraint_store.release();
		classification_constraint_store.release();
		resultClassification_constraint_store.release();
		queryFullUri_constraint_store.release();
		logicalName_constraint_store.release();
		realisation_constraint_store.release();
		queryisMemberOf_constraint_store.release();
		ResultVec_constraint_store.release();
	}
	static chr::Shared_obj<OWL2> create() { return chr::make_shared<OWL2>(); }
	chr::Constraint_stores_iterator<chr::Shared_obj<typename owlPrefix::Constraint_store_t>,chr::Shared_obj<typename owlClass::Constraint_store_t>,chr::Shared_obj<typename owlObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlDataProperty::Constraint_store_t>,chr::Shared_obj<typename owlNamedIndividual::Constraint_store_t>,chr::Shared_obj<typename owlSubclassOf::Constraint_store_t>,chr::Shared_obj<typename owlEquivalentClass::Constraint_store_t>,chr::Shared_obj<typename owlSubDataPropertyOf::Constraint_store_t>,chr::Shared_obj<typename owlSubObjectPropertyOf::Constraint_store_t>,chr::Shared_obj<typename owlEquivalentDataProperty::Constraint_store_t>,chr::Shared_obj<typename owlEquivalentObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlObjectPropertyDomain::Constraint_store_t>,chr::Shared_obj<typename owlDataPropertyDomain::Constraint_store_t>,chr::Shared_obj<typename owlObjectPropertyRange::Constraint_store_t>,chr::Shared_obj<typename owlClassAssertion::Constraint_store_t>,chr::Shared_obj<typename owlDisjointClass::Constraint_store_t>,chr::Shared_obj<typename owlNegativeObjectAssertion::Constraint_store_t>,chr::Shared_obj<typename owlObjectPropertyAssertion::Constraint_store_t>,chr::Shared_obj<typename owlSameIndividual::Constraint_store_t>,chr::Shared_obj<typename owlDifferentIndividual::Constraint_store_t>,chr::Shared_obj<typename owlInverseObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlSymmetricObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlAsymmetricObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlDisjointObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlDisjointDataProperty::Constraint_store_t>,chr::Shared_obj<typename owlReflexiveObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlIrreflexiveObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlFunctionalObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlFunctionalDataProperty::Constraint_store_t>,chr::Shared_obj<typename owlInverseFunctionalObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlTransitiveObjectProperty::Constraint_store_t>,chr::Shared_obj<typename owlDataPropertyAssertion::Constraint_store_t>,chr::Shared_obj<typename owlNegativeDataAssertion::Constraint_store_t>,chr::Shared_obj<typename owlDataPropertyRange::Constraint_store_t>,chr::Shared_obj<typename owlUnionClass::Constraint_store_t>,chr::Shared_obj<typename owlUnionOf::Constraint_store_t>,chr::Shared_obj<typename owlIntersectionOf::Constraint_store_t>,chr::Shared_obj<typename owlIntersectionClass::Constraint_store_t>,chr::Shared_obj<typename owlIntersectionOfLoop::Constraint_store_t>,chr::Shared_obj<typename intersectionSubclassCheck::Constraint_store_t>,chr::Shared_obj<typename owlCandidatsIntersection::Constraint_store_t>,chr::Shared_obj<typename owlObjectAllValuesFrom::Constraint_store_t>,chr::Shared_obj<typename owlDataAllValuesFrom::Constraint_store_t>,chr::Shared_obj<typename owlObjectSomeValuesFrom::Constraint_store_t>,chr::Shared_obj<typename owlDataSomeValuesFrom::Constraint_store_t>,chr::Shared_obj<typename owlDataValue::Constraint_store_t>,chr::Shared_obj<typename owlComplementOf::Constraint_store_t>,chr::Shared_obj<typename owlObjectMaxCardinality::Constraint_store_t>,chr::Shared_obj<typename owlDataMaxCardinality::Constraint_store_t>,chr::Shared_obj<typename owlHasValueObject::Constraint_store_t>,chr::Shared_obj<typename owlOneOf::Constraint_store_t>,chr::Shared_obj<typename owlObjectPropertyChain::Constraint_store_t>,chr::Shared_obj<typename constructPropertyChain::Constraint_store_t>,chr::Shared_obj<typename owlHasKey::Constraint_store_t>,chr::Shared_obj<typename owlHasKeyCheck::Constraint_store_t>,chr::Shared_obj<typename querySuperClassOfUri::Constraint_store_t>,chr::Shared_obj<typename querySuperClassOfClassUri::Constraint_store_t>,chr::Shared_obj<typename querySubClassOfUri::Constraint_store_t>,chr::Shared_obj<typename querySubClassOfClassUri::Constraint_store_t>,chr::Shared_obj<typename querySuperClassOf::Constraint_store_t>,chr::Shared_obj<typename querySuperClassOfReal::Constraint_store_t>,chr::Shared_obj<typename querySubClassOf::Constraint_store_t>,chr::Shared_obj<typename queryClassification::Constraint_store_t>,chr::Shared_obj<typename queryClassificationReal::Constraint_store_t>,chr::Shared_obj<typename queryClassificationUri::Constraint_store_t>,chr::Shared_obj<typename queryClassificationTemp::Constraint_store_t>,chr::Shared_obj<typename queryClassificationTempUri::Constraint_store_t>,chr::Shared_obj<typename queryInstanceURI::Constraint_store_t>,chr::Shared_obj<typename queryInstances::Constraint_store_t>,chr::Shared_obj<typename queryObjAssertion::Constraint_store_t>,chr::Shared_obj<typename querySubjectByObject::Constraint_store_t>,chr::Shared_obj<typename queryDataAssertion::Constraint_store_t>,chr::Shared_obj<typename queryEngineeringStudents::Constraint_store_t>,chr::Shared_obj<typename queryComplexStudents::Constraint_store_t>,chr::Shared_obj<typename queryObjAssertionSubject::Constraint_store_t>,chr::Shared_obj<typename queryObjAssertionClassUri::Constraint_store_t>,chr::Shared_obj<typename queryObjAssertionClass::Constraint_store_t>,chr::Shared_obj<typename queryEquivalentClass::Constraint_store_t>,chr::Shared_obj<typename queryEquivalentClassReal::Constraint_store_t>,chr::Shared_obj<typename res::Constraint_store_t>,chr::Shared_obj<typename resultRealisation::Constraint_store_t>,chr::Shared_obj<typename classification::Constraint_store_t>,chr::Shared_obj<typename resultClassification::Constraint_store_t>,chr::Shared_obj<typename queryFullUri::Constraint_store_t>,chr::Shared_obj<typename logicalName::Constraint_store_t>,chr::Shared_obj<typename realisation::Constraint_store_t>,chr::Shared_obj<typename queryisMemberOf::Constraint_store_t>,chr::Shared_obj<typename ResultVec::Constraint_store_t>> chr_store_begin() { return chr::Constraint_stores_iterator(owlPrefix_constraint_store,owlClass_constraint_store,owlObjectProperty_constraint_store,owlDataProperty_constraint_store,owlNamedIndividual_constraint_store,owlSubclassOf_constraint_store,owlEquivalentClass_constraint_store,owlSubDataPropertyOf_constraint_store,owlSubObjectPropertyOf_constraint_store,owlEquivalentDataProperty_constraint_store,owlEquivalentObjectProperty_constraint_store,owlObjectPropertyDomain_constraint_store,owlDataPropertyDomain_constraint_store,owlObjectPropertyRange_constraint_store,owlClassAssertion_constraint_store,owlDisjointClass_constraint_store,owlNegativeObjectAssertion_constraint_store,owlObjectPropertyAssertion_constraint_store,owlSameIndividual_constraint_store,owlDifferentIndividual_constraint_store,owlInverseObjectProperty_constraint_store,owlSymmetricObjectProperty_constraint_store,owlAsymmetricObjectProperty_constraint_store,owlDisjointObjectProperty_constraint_store,owlDisjointDataProperty_constraint_store,owlReflexiveObjectProperty_constraint_store,owlIrreflexiveObjectProperty_constraint_store,owlFunctionalObjectProperty_constraint_store,owlFunctionalDataProperty_constraint_store,owlInverseFunctionalObjectProperty_constraint_store,owlTransitiveObjectProperty_constraint_store,owlDataPropertyAssertion_constraint_store,owlNegativeDataAssertion_constraint_store,owlDataPropertyRange_constraint_store,owlUnionClass_constraint_store,owlUnionOf_constraint_store,owlIntersectionOf_constraint_store,owlIntersectionClass_constraint_store,owlIntersectionOfLoop_constraint_store,intersectionSubclassCheck_constraint_store,owlCandidatsIntersection_constraint_store,owlObjectAllValuesFrom_constraint_store,owlDataAllValuesFrom_constraint_store,owlObjectSomeValuesFrom_constraint_store,owlDataSomeValuesFrom_constraint_store,owlDataValue_constraint_store,owlComplementOf_constraint_store,owlObjectMaxCardinality_constraint_store,owlDataMaxCardinality_constraint_store,owlHasValueObject_constraint_store,owlOneOf_constraint_store,owlObjectPropertyChain_constraint_store,constructPropertyChain_constraint_store,owlHasKey_constraint_store,owlHasKeyCheck_constraint_store,querySuperClassOfUri_constraint_store,querySuperClassOfClassUri_constraint_store,querySubClassOfUri_constraint_store,querySubClassOfClassUri_constraint_store,querySuperClassOf_constraint_store,querySuperClassOfReal_constraint_store,querySubClassOf_constraint_store,queryClassification_constraint_store,queryClassificationReal_constraint_store,queryClassificationUri_constraint_store,queryClassificationTemp_constraint_store,queryClassificationTempUri_constraint_store,queryInstanceURI_constraint_store,queryInstances_constraint_store,queryObjAssertion_constraint_store,querySubjectByObject_constraint_store,queryDataAssertion_constraint_store,queryEngineeringStudents_constraint_store,queryComplexStudents_constraint_store,queryObjAssertionSubject_constraint_store,queryObjAssertionClassUri_constraint_store,queryObjAssertionClass_constraint_store,queryEquivalentClass_constraint_store,queryEquivalentClassReal_constraint_store,res_constraint_store,resultRealisation_constraint_store,classification_constraint_store,resultClassification_constraint_store,queryFullUri_constraint_store,logicalName_constraint_store,realisation_constraint_store,queryisMemberOf_constraint_store,ResultVec_constraint_store); }
	typename owlPrefix::Constraint_store_t& get_owlPrefix_store() { return *owlPrefix_constraint_store; }
	typename owlClass::Constraint_store_t& get_owlClass_store() { return *owlClass_constraint_store; }
	typename owlObjectProperty::Constraint_store_t& get_owlObjectProperty_store() { return *owlObjectProperty_constraint_store; }
	typename owlDataProperty::Constraint_store_t& get_owlDataProperty_store() { return *owlDataProperty_constraint_store; }
	typename owlNamedIndividual::Constraint_store_t& get_owlNamedIndividual_store() { return *owlNamedIndividual_constraint_store; }
	typename owlSubclassOf::Constraint_store_t& get_owlSubclassOf_store() { return *owlSubclassOf_constraint_store; }
	typename owlEquivalentClass::Constraint_store_t& get_owlEquivalentClass_store() { return *owlEquivalentClass_constraint_store; }
	typename owlSubDataPropertyOf::Constraint_store_t& get_owlSubDataPropertyOf_store() { return *owlSubDataPropertyOf_constraint_store; }
	typename owlSubObjectPropertyOf::Constraint_store_t& get_owlSubObjectPropertyOf_store() { return *owlSubObjectPropertyOf_constraint_store; }
	typename owlEquivalentDataProperty::Constraint_store_t& get_owlEquivalentDataProperty_store() { return *owlEquivalentDataProperty_constraint_store; }
	typename owlEquivalentObjectProperty::Constraint_store_t& get_owlEquivalentObjectProperty_store() { return *owlEquivalentObjectProperty_constraint_store; }
	typename owlObjectPropertyDomain::Constraint_store_t& get_owlObjectPropertyDomain_store() { return *owlObjectPropertyDomain_constraint_store; }
	typename owlDataPropertyDomain::Constraint_store_t& get_owlDataPropertyDomain_store() { return *owlDataPropertyDomain_constraint_store; }
	typename owlObjectPropertyRange::Constraint_store_t& get_owlObjectPropertyRange_store() { return *owlObjectPropertyRange_constraint_store; }
	typename owlClassAssertion::Constraint_store_t& get_owlClassAssertion_store() { return *owlClassAssertion_constraint_store; }
	typename owlDisjointClass::Constraint_store_t& get_owlDisjointClass_store() { return *owlDisjointClass_constraint_store; }
	typename owlNegativeObjectAssertion::Constraint_store_t& get_owlNegativeObjectAssertion_store() { return *owlNegativeObjectAssertion_constraint_store; }
	typename owlObjectPropertyAssertion::Constraint_store_t& get_owlObjectPropertyAssertion_store() { return *owlObjectPropertyAssertion_constraint_store; }
	typename owlSameIndividual::Constraint_store_t& get_owlSameIndividual_store() { return *owlSameIndividual_constraint_store; }
	typename owlDifferentIndividual::Constraint_store_t& get_owlDifferentIndividual_store() { return *owlDifferentIndividual_constraint_store; }
	typename owlInverseObjectProperty::Constraint_store_t& get_owlInverseObjectProperty_store() { return *owlInverseObjectProperty_constraint_store; }
	typename owlSymmetricObjectProperty::Constraint_store_t& get_owlSymmetricObjectProperty_store() { return *owlSymmetricObjectProperty_constraint_store; }
	typename owlAsymmetricObjectProperty::Constraint_store_t& get_owlAsymmetricObjectProperty_store() { return *owlAsymmetricObjectProperty_constraint_store; }
	typename owlDisjointObjectProperty::Constraint_store_t& get_owlDisjointObjectProperty_store() { return *owlDisjointObjectProperty_constraint_store; }
	typename owlDisjointDataProperty::Constraint_store_t& get_owlDisjointDataProperty_store() { return *owlDisjointDataProperty_constraint_store; }
	typename owlReflexiveObjectProperty::Constraint_store_t& get_owlReflexiveObjectProperty_store() { return *owlReflexiveObjectProperty_constraint_store; }
	typename owlIrreflexiveObjectProperty::Constraint_store_t& get_owlIrreflexiveObjectProperty_store() { return *owlIrreflexiveObjectProperty_constraint_store; }
	typename owlFunctionalObjectProperty::Constraint_store_t& get_owlFunctionalObjectProperty_store() { return *owlFunctionalObjectProperty_constraint_store; }
	typename owlFunctionalDataProperty::Constraint_store_t& get_owlFunctionalDataProperty_store() { return *owlFunctionalDataProperty_constraint_store; }
	typename owlInverseFunctionalObjectProperty::Constraint_store_t& get_owlInverseFunctionalObjectProperty_store() { return *owlInverseFunctionalObjectProperty_constraint_store; }
	typename owlTransitiveObjectProperty::Constraint_store_t& get_owlTransitiveObjectProperty_store() { return *owlTransitiveObjectProperty_constraint_store; }
	typename owlDataPropertyAssertion::Constraint_store_t& get_owlDataPropertyAssertion_store() { return *owlDataPropertyAssertion_constraint_store; }
	typename owlNegativeDataAssertion::Constraint_store_t& get_owlNegativeDataAssertion_store() { return *owlNegativeDataAssertion_constraint_store; }
	typename owlDataPropertyRange::Constraint_store_t& get_owlDataPropertyRange_store() { return *owlDataPropertyRange_constraint_store; }
	typename owlUnionClass::Constraint_store_t& get_owlUnionClass_store() { return *owlUnionClass_constraint_store; }
	typename owlUnionOf::Constraint_store_t& get_owlUnionOf_store() { return *owlUnionOf_constraint_store; }
	typename owlIntersectionOf::Constraint_store_t& get_owlIntersectionOf_store() { return *owlIntersectionOf_constraint_store; }
	typename owlIntersectionClass::Constraint_store_t& get_owlIntersectionClass_store() { return *owlIntersectionClass_constraint_store; }
	typename owlIntersectionOfLoop::Constraint_store_t& get_owlIntersectionOfLoop_store() { return *owlIntersectionOfLoop_constraint_store; }
	typename intersectionSubclassCheck::Constraint_store_t& get_intersectionSubclassCheck_store() { return *intersectionSubclassCheck_constraint_store; }
	typename owlCandidatsIntersection::Constraint_store_t& get_owlCandidatsIntersection_store() { return *owlCandidatsIntersection_constraint_store; }
	typename owlObjectAllValuesFrom::Constraint_store_t& get_owlObjectAllValuesFrom_store() { return *owlObjectAllValuesFrom_constraint_store; }
	typename owlDataAllValuesFrom::Constraint_store_t& get_owlDataAllValuesFrom_store() { return *owlDataAllValuesFrom_constraint_store; }
	typename owlObjectSomeValuesFrom::Constraint_store_t& get_owlObjectSomeValuesFrom_store() { return *owlObjectSomeValuesFrom_constraint_store; }
	typename owlDataSomeValuesFrom::Constraint_store_t& get_owlDataSomeValuesFrom_store() { return *owlDataSomeValuesFrom_constraint_store; }
	typename owlDataValue::Constraint_store_t& get_owlDataValue_store() { return *owlDataValue_constraint_store; }
	typename owlComplementOf::Constraint_store_t& get_owlComplementOf_store() { return *owlComplementOf_constraint_store; }
	typename owlObjectMaxCardinality::Constraint_store_t& get_owlObjectMaxCardinality_store() { return *owlObjectMaxCardinality_constraint_store; }
	typename owlDataMaxCardinality::Constraint_store_t& get_owlDataMaxCardinality_store() { return *owlDataMaxCardinality_constraint_store; }
	typename owlHasValueObject::Constraint_store_t& get_owlHasValueObject_store() { return *owlHasValueObject_constraint_store; }
	typename owlOneOf::Constraint_store_t& get_owlOneOf_store() { return *owlOneOf_constraint_store; }
	typename owlObjectPropertyChain::Constraint_store_t& get_owlObjectPropertyChain_store() { return *owlObjectPropertyChain_constraint_store; }
	typename constructPropertyChain::Constraint_store_t& get_constructPropertyChain_store() { return *constructPropertyChain_constraint_store; }
	typename owlHasKey::Constraint_store_t& get_owlHasKey_store() { return *owlHasKey_constraint_store; }
	typename owlHasKeyCheck::Constraint_store_t& get_owlHasKeyCheck_store() { return *owlHasKeyCheck_constraint_store; }
	typename querySuperClassOfUri::Constraint_store_t& get_querySuperClassOfUri_store() { return *querySuperClassOfUri_constraint_store; }
	typename querySuperClassOfClassUri::Constraint_store_t& get_querySuperClassOfClassUri_store() { return *querySuperClassOfClassUri_constraint_store; }
	typename querySubClassOfUri::Constraint_store_t& get_querySubClassOfUri_store() { return *querySubClassOfUri_constraint_store; }
	typename querySubClassOfClassUri::Constraint_store_t& get_querySubClassOfClassUri_store() { return *querySubClassOfClassUri_constraint_store; }
	typename querySuperClassOf::Constraint_store_t& get_querySuperClassOf_store() { return *querySuperClassOf_constraint_store; }
	typename querySuperClassOfReal::Constraint_store_t& get_querySuperClassOfReal_store() { return *querySuperClassOfReal_constraint_store; }
	typename querySubClassOf::Constraint_store_t& get_querySubClassOf_store() { return *querySubClassOf_constraint_store; }
	typename queryClassification::Constraint_store_t& get_queryClassification_store() { return *queryClassification_constraint_store; }
	typename queryClassificationReal::Constraint_store_t& get_queryClassificationReal_store() { return *queryClassificationReal_constraint_store; }
	typename queryClassificationUri::Constraint_store_t& get_queryClassificationUri_store() { return *queryClassificationUri_constraint_store; }
	typename queryClassificationTemp::Constraint_store_t& get_queryClassificationTemp_store() { return *queryClassificationTemp_constraint_store; }
	typename queryClassificationTempUri::Constraint_store_t& get_queryClassificationTempUri_store() { return *queryClassificationTempUri_constraint_store; }
	typename queryInstanceURI::Constraint_store_t& get_queryInstanceURI_store() { return *queryInstanceURI_constraint_store; }
	typename queryInstances::Constraint_store_t& get_queryInstances_store() { return *queryInstances_constraint_store; }
	typename queryObjAssertion::Constraint_store_t& get_queryObjAssertion_store() { return *queryObjAssertion_constraint_store; }
	typename querySubjectByObject::Constraint_store_t& get_querySubjectByObject_store() { return *querySubjectByObject_constraint_store; }
	typename queryDataAssertion::Constraint_store_t& get_queryDataAssertion_store() { return *queryDataAssertion_constraint_store; }
	typename queryEngineeringStudents::Constraint_store_t& get_queryEngineeringStudents_store() { return *queryEngineeringStudents_constraint_store; }
	typename queryComplexStudents::Constraint_store_t& get_queryComplexStudents_store() { return *queryComplexStudents_constraint_store; }
	typename queryObjAssertionSubject::Constraint_store_t& get_queryObjAssertionSubject_store() { return *queryObjAssertionSubject_constraint_store; }
	typename queryObjAssertionClassUri::Constraint_store_t& get_queryObjAssertionClassUri_store() { return *queryObjAssertionClassUri_constraint_store; }
	typename queryObjAssertionClass::Constraint_store_t& get_queryObjAssertionClass_store() { return *queryObjAssertionClass_constraint_store; }
	typename queryEquivalentClass::Constraint_store_t& get_queryEquivalentClass_store() { return *queryEquivalentClass_constraint_store; }
	typename queryEquivalentClassReal::Constraint_store_t& get_queryEquivalentClassReal_store() { return *queryEquivalentClassReal_constraint_store; }
	typename res::Constraint_store_t& get_res_store() { return *res_constraint_store; }
	typename resultRealisation::Constraint_store_t& get_resultRealisation_store() { return *resultRealisation_constraint_store; }
	typename classification::Constraint_store_t& get_classification_store() { return *classification_constraint_store; }
	typename resultClassification::Constraint_store_t& get_resultClassification_store() { return *resultClassification_constraint_store; }
	typename queryFullUri::Constraint_store_t& get_queryFullUri_store() { return *queryFullUri_constraint_store; }
	typename logicalName::Constraint_store_t& get_logicalName_store() { return *logicalName_constraint_store; }
	typename realisation::Constraint_store_t& get_realisation_store() { return *realisation_constraint_store; }
	typename queryisMemberOf::Constraint_store_t& get_queryisMemberOf_store() { return *queryisMemberOf_constraint_store; }
	typename ResultVec::Constraint_store_t& get_ResultVec_store() { return *ResultVec_constraint_store; }
	struct History {
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_97{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_98{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_99{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_100{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_101{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_102{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_103{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_104{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_105{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_106{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_107{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_108{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_109{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_110{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_111{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_112{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_113{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_114{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_115{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_116{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_117{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_118{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_120{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_121{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_122{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_123{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_124{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_125{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_126{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_127{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_128{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_129{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_130{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_131{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_132{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_134{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_135{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_136{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_137{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_138{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_139{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_141{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_142{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_143{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_147{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_148{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_149{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_151{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_152{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_153{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_154{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_155{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_157{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_158{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_160{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_163{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_164{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_165{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_167{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_168{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_174{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_175{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_176{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 4 > > rule_177{ chr::make_shared< typename chr::History_dyn< 4 > >() };
		typename chr::Shared_obj< chr::History_dyn< 4 > > rule_178{ chr::make_shared< typename chr::History_dyn< 4 > >() };
		typename chr::Shared_obj< chr::History_dyn< 5 > > rule_179{ chr::make_shared< typename chr::History_dyn< 5 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_180{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_184{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_185{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_189{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_193{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_194{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_195{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_199{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_200{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_201{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 2 > > rule_205{ chr::make_shared< typename chr::History_dyn< 2 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_206{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_210{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 4 > > rule_211{ chr::make_shared< typename chr::History_dyn< 4 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_212{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_214{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 5 > > rule_215{ chr::make_shared< typename chr::History_dyn< 5 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_216{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_217{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 1 > > rule_218{ chr::make_shared< typename chr::History_dyn< 1 > >() };
		typename chr::Shared_obj< chr::History_dyn< 4 > > rule_222{ chr::make_shared< typename chr::History_dyn< 4 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_223{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_228{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_233{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 3 > > rule_238{ chr::make_shared< typename chr::History_dyn< 3 > >() };
		typename chr::Shared_obj< chr::History_dyn< 4 > > rule_243{ chr::make_shared< typename chr::History_dyn< 4 > >() };
		typename chr::Shared_obj< chr::History_dyn< 7 > > rule_248{ chr::make_shared< typename chr::History_dyn< 7 > >() };
		typename chr::Shared_obj< chr::History_dyn< 8 > > rule_253{ chr::make_shared< typename chr::History_dyn< 8 > >() };
	};
	History _history;
	chr::ES_CHR do_owlPrefix(typename owlPrefix::Type c_args, typename owlPrefix::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlPrefix( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlPrefix(std::move(c_args), owlPrefix_constraint_store->end());
	}
	chr::ES_CHR do_owlClass(typename owlClass::Type c_args, typename owlClass::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlClass( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlClass(std::move(c_args), owlClass_constraint_store->end());
	}
	chr::ES_CHR do_owlObjectProperty(typename owlObjectProperty::Type c_args, typename owlObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlObjectProperty( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlObjectProperty(std::move(c_args), owlObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlDataProperty(typename owlDataProperty::Type c_args, typename owlDataProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDataProperty( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlDataProperty(std::move(c_args), owlDataProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlNamedIndividual(typename owlNamedIndividual::Type c_args, typename owlNamedIndividual::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlNamedIndividual( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlNamedIndividual(std::move(c_args), owlNamedIndividual_constraint_store->end());
	}
	chr::ES_CHR do_owlSubclassOf(typename owlSubclassOf::Type c_args, typename owlSubclassOf::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlSubclassOf( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlSubclassOf(std::move(c_args), owlSubclassOf_constraint_store->end());
	}
	chr::ES_CHR do_owlEquivalentClass(typename owlEquivalentClass::Type c_args, typename owlEquivalentClass::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlEquivalentClass( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlEquivalentClass(std::move(c_args), owlEquivalentClass_constraint_store->end());
	}
	chr::ES_CHR do_owlSubDataPropertyOf(typename owlSubDataPropertyOf::Type c_args, typename owlSubDataPropertyOf::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlSubDataPropertyOf( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlSubDataPropertyOf(std::move(c_args), owlSubDataPropertyOf_constraint_store->end());
	}
	chr::ES_CHR do_owlSubObjectPropertyOf(typename owlSubObjectPropertyOf::Type c_args, typename owlSubObjectPropertyOf::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlSubObjectPropertyOf( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlSubObjectPropertyOf(std::move(c_args), owlSubObjectPropertyOf_constraint_store->end());
	}
	chr::ES_CHR do_owlEquivalentDataProperty(typename owlEquivalentDataProperty::Type c_args, typename owlEquivalentDataProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlEquivalentDataProperty( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlEquivalentDataProperty(std::move(c_args), owlEquivalentDataProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlEquivalentObjectProperty(typename owlEquivalentObjectProperty::Type c_args, typename owlEquivalentObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlEquivalentObjectProperty( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlEquivalentObjectProperty(std::move(c_args), owlEquivalentObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlObjectPropertyDomain(typename owlObjectPropertyDomain::Type c_args, typename owlObjectPropertyDomain::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlObjectPropertyDomain( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlObjectPropertyDomain(std::move(c_args), owlObjectPropertyDomain_constraint_store->end());
	}
	chr::ES_CHR do_owlDataPropertyDomain(typename owlDataPropertyDomain::Type c_args, typename owlDataPropertyDomain::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDataPropertyDomain( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlDataPropertyDomain(std::move(c_args), owlDataPropertyDomain_constraint_store->end());
	}
	chr::ES_CHR do_owlObjectPropertyRange(typename owlObjectPropertyRange::Type c_args, typename owlObjectPropertyRange::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlObjectPropertyRange( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlObjectPropertyRange(std::move(c_args), owlObjectPropertyRange_constraint_store->end());
	}
	chr::ES_CHR do_owlClassAssertion(typename owlClassAssertion::Type c_args, typename owlClassAssertion::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlClassAssertion( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< bool > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlClassAssertion(std::move(c_args), owlClassAssertion_constraint_store->end());
	}
	chr::ES_CHR do_owlDisjointClass(typename owlDisjointClass::Type c_args, typename owlDisjointClass::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDisjointClass( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlDisjointClass(std::move(c_args), owlDisjointClass_constraint_store->end());
	}
	chr::ES_CHR do_owlNegativeObjectAssertion(typename owlNegativeObjectAssertion::Type c_args, typename owlNegativeObjectAssertion::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlNegativeObjectAssertion( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlNegativeObjectAssertion(std::move(c_args), owlNegativeObjectAssertion_constraint_store->end());
	}
	chr::ES_CHR do_owlObjectPropertyAssertion(typename owlObjectPropertyAssertion::Type c_args, typename owlObjectPropertyAssertion::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlObjectPropertyAssertion( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlObjectPropertyAssertion(std::move(c_args), owlObjectPropertyAssertion_constraint_store->end());
	}
	chr::ES_CHR do_owlSameIndividual(typename owlSameIndividual::Type c_args, typename owlSameIndividual::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlSameIndividual( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlSameIndividual(std::move(c_args), owlSameIndividual_constraint_store->end());
	}
	chr::ES_CHR do_owlDifferentIndividual(typename owlDifferentIndividual::Type c_args, typename owlDifferentIndividual::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDifferentIndividual( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlDifferentIndividual(std::move(c_args), owlDifferentIndividual_constraint_store->end());
	}
	chr::ES_CHR do_owlInverseObjectProperty(typename owlInverseObjectProperty::Type c_args, typename owlInverseObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlInverseObjectProperty( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlInverseObjectProperty(std::move(c_args), owlInverseObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlSymmetricObjectProperty(typename owlSymmetricObjectProperty::Type c_args, typename owlSymmetricObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlSymmetricObjectProperty( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlSymmetricObjectProperty(std::move(c_args), owlSymmetricObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlAsymmetricObjectProperty(typename owlAsymmetricObjectProperty::Type c_args, typename owlAsymmetricObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlAsymmetricObjectProperty( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlAsymmetricObjectProperty(std::move(c_args), owlAsymmetricObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlDisjointObjectProperty(typename owlDisjointObjectProperty::Type c_args, typename owlDisjointObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDisjointObjectProperty( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlDisjointObjectProperty(std::move(c_args), owlDisjointObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlDisjointDataProperty(typename owlDisjointDataProperty::Type c_args, typename owlDisjointDataProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDisjointDataProperty( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlDisjointDataProperty(std::move(c_args), owlDisjointDataProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlReflexiveObjectProperty(typename owlReflexiveObjectProperty::Type c_args, typename owlReflexiveObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlReflexiveObjectProperty( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlReflexiveObjectProperty(std::move(c_args), owlReflexiveObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlIrreflexiveObjectProperty(typename owlIrreflexiveObjectProperty::Type c_args, typename owlIrreflexiveObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlIrreflexiveObjectProperty( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlIrreflexiveObjectProperty(std::move(c_args), owlIrreflexiveObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlFunctionalObjectProperty(typename owlFunctionalObjectProperty::Type c_args, typename owlFunctionalObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlFunctionalObjectProperty( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlFunctionalObjectProperty(std::move(c_args), owlFunctionalObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlFunctionalDataProperty(typename owlFunctionalDataProperty::Type c_args, typename owlFunctionalDataProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlFunctionalDataProperty( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlFunctionalDataProperty(std::move(c_args), owlFunctionalDataProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlInverseFunctionalObjectProperty(typename owlInverseFunctionalObjectProperty::Type c_args, typename owlInverseFunctionalObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlInverseFunctionalObjectProperty( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlInverseFunctionalObjectProperty(std::move(c_args), owlInverseFunctionalObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlTransitiveObjectProperty(typename owlTransitiveObjectProperty::Type c_args, typename owlTransitiveObjectProperty::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlTransitiveObjectProperty( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_owlTransitiveObjectProperty(std::move(c_args), owlTransitiveObjectProperty_constraint_store->end());
	}
	chr::ES_CHR do_owlDataPropertyAssertion(typename owlDataPropertyAssertion::Type c_args, typename owlDataPropertyAssertion::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDataPropertyAssertion( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< Value > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlDataPropertyAssertion(std::move(c_args), owlDataPropertyAssertion_constraint_store->end());
	}
	chr::ES_CHR do_owlNegativeDataAssertion(typename owlNegativeDataAssertion::Type c_args, typename owlNegativeDataAssertion::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlNegativeDataAssertion( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< Value > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlNegativeDataAssertion(std::move(c_args), owlNegativeDataAssertion_constraint_store->end());
	}
	chr::ES_CHR do_owlDataPropertyRange(typename owlDataPropertyRange::Type c_args, typename owlDataPropertyRange::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDataPropertyRange( chr::Logical_var< int > arg0, chr::Logical_var_ground< std :: shared_ptr< AnySimpleType > > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlDataPropertyRange(std::move(c_args), owlDataPropertyRange_constraint_store->end());
	}
	chr::ES_CHR do_owlUnionClass(typename owlUnionClass::Type c_args, typename owlUnionClass::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlUnionClass( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlUnionClass(std::move(c_args), owlUnionClass_constraint_store->end());
	}
	chr::ES_CHR do_owlUnionOf(typename owlUnionOf::Type c_args, typename owlUnionOf::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlUnionOf( chr::Logical_var< int > arg0, chr::Logical_var_ground< LogicalVarSet > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlUnionOf(std::move(c_args), owlUnionOf_constraint_store->end());
	}
	chr::ES_CHR do_owlUnionOfLoop(typename owlUnionOfLoop::Type c_args);
	chr::ES_CHR owlUnionOfLoop( chr::Logical_var< int > arg0, chr::Logical_var_ground< LogicalVarSetIterator > arg1, chr::Logical_var_ground< LogicalVarSetIterator > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlUnionOfLoop(std::move(c_args));
	}
	chr::ES_CHR do_owlIntersectionOf(typename owlIntersectionOf::Type c_args, typename owlIntersectionOf::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlIntersectionOf( chr::Logical_var< int > arg0, chr::Logical_var_ground< LogicalVarSet > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlIntersectionOf(std::move(c_args), owlIntersectionOf_constraint_store->end());
	}
	chr::ES_CHR do_owlIntersectionClass(typename owlIntersectionClass::Type c_args, typename owlIntersectionClass::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlIntersectionClass( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlIntersectionClass(std::move(c_args), owlIntersectionClass_constraint_store->end());
	}
	chr::ES_CHR do_owlIntersectionOfLoop(typename owlIntersectionOfLoop::Type c_args, typename owlIntersectionOfLoop::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlIntersectionOfLoop( chr::Logical_var< int > arg0, chr::Logical_var_ground< LogicalVarSetIterator > arg1, chr::Logical_var_ground< LogicalVarSetIterator > arg2, chr::Logical_var_ground< int > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_owlIntersectionOfLoop(std::move(c_args), owlIntersectionOfLoop_constraint_store->end());
	}
	chr::ES_CHR do_intersectionSubclassCheck(typename intersectionSubclassCheck::Type c_args, typename intersectionSubclassCheck::Constraint_store_t::iterator c_it);
	chr::ES_CHR intersectionSubclassCheck( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_intersectionSubclassCheck(std::move(c_args), intersectionSubclassCheck_constraint_store->end());
	}
	chr::ES_CHR do_owlCandidatsIntersection(typename owlCandidatsIntersection::Type c_args, typename owlCandidatsIntersection::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlCandidatsIntersection( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlCandidatsIntersection(std::move(c_args), owlCandidatsIntersection_constraint_store->end());
	}
	chr::ES_CHR do_owlObjectAllValuesFrom(typename owlObjectAllValuesFrom::Type c_args, typename owlObjectAllValuesFrom::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlObjectAllValuesFrom( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlObjectAllValuesFrom(std::move(c_args), owlObjectAllValuesFrom_constraint_store->end());
	}
	chr::ES_CHR do_owlDataAllValuesFrom(typename owlDataAllValuesFrom::Type c_args, typename owlDataAllValuesFrom::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDataAllValuesFrom( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< std :: shared_ptr< AnySimpleType > > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlDataAllValuesFrom(std::move(c_args), owlDataAllValuesFrom_constraint_store->end());
	}
	chr::ES_CHR do_owlObjectSomeValuesFrom(typename owlObjectSomeValuesFrom::Type c_args, typename owlObjectSomeValuesFrom::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlObjectSomeValuesFrom( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlObjectSomeValuesFrom(std::move(c_args), owlObjectSomeValuesFrom_constraint_store->end());
	}
	chr::ES_CHR do_owlDataSomeValuesFrom(typename owlDataSomeValuesFrom::Type c_args, typename owlDataSomeValuesFrom::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDataSomeValuesFrom( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< std :: shared_ptr< AnySimpleType > > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlDataSomeValuesFrom(std::move(c_args), owlDataSomeValuesFrom_constraint_store->end());
	}
	chr::ES_CHR do_owlDataValue(typename owlDataValue::Type c_args, typename owlDataValue::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDataValue( chr::Logical_var_ground< Value > arg0, chr::Logical_var_ground< std :: string > arg1, chr::Logical_var_ground< std :: shared_ptr< AnySimpleType > > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlDataValue(std::move(c_args), owlDataValue_constraint_store->end());
	}
	chr::ES_CHR do_owlComplementOf(typename owlComplementOf::Type c_args, typename owlComplementOf::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlComplementOf( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlComplementOf(std::move(c_args), owlComplementOf_constraint_store->end());
	}
	chr::ES_CHR do_owlObjectMaxCardinality(typename owlObjectMaxCardinality::Type c_args, typename owlObjectMaxCardinality::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlObjectMaxCardinality( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlObjectMaxCardinality(std::move(c_args), owlObjectMaxCardinality_constraint_store->end());
	}
	chr::ES_CHR do_owlDataMaxCardinality(typename owlDataMaxCardinality::Type c_args, typename owlDataMaxCardinality::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlDataMaxCardinality( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlDataMaxCardinality(std::move(c_args), owlDataMaxCardinality_constraint_store->end());
	}
	chr::ES_CHR do_owlHasValueObject(typename owlHasValueObject::Type c_args, typename owlHasValueObject::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlHasValueObject( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlHasValueObject(std::move(c_args), owlHasValueObject_constraint_store->end());
	}
	chr::ES_CHR do_owlOneOf(typename owlOneOf::Type c_args, typename owlOneOf::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlOneOf( chr::Logical_var< int > arg0, chr::Logical_var_ground< LogicalVarSet > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_owlOneOf(std::move(c_args), owlOneOf_constraint_store->end());
	}
	chr::ES_CHR do_owlOneOfLoop(typename owlOneOfLoop::Type c_args);
	chr::ES_CHR owlOneOfLoop( chr::Logical_var< int > arg0, chr::Logical_var_ground< LogicalVarSetIterator > arg1, chr::Logical_var_ground< LogicalVarSetIterator > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_owlOneOfLoop(std::move(c_args));
	}
	chr::ES_CHR do_owlObjectPropertyChain(typename owlObjectPropertyChain::Type c_args, typename owlObjectPropertyChain::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlObjectPropertyChain( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var_ground< int > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_owlObjectPropertyChain(std::move(c_args), owlObjectPropertyChain_constraint_store->end());
	}
	chr::ES_CHR do_constructPropertyChain(typename constructPropertyChain::Type c_args, typename constructPropertyChain::Constraint_store_t::iterator c_it);
	chr::ES_CHR constructPropertyChain( chr::Logical_var< int > arg0, chr::Logical_var_ground< int > arg1, chr::Logical_var< int > arg2, chr::Logical_var< int > arg3, chr::Logical_var_ground< int > arg4) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4);
		return do_constructPropertyChain(std::move(c_args), constructPropertyChain_constraint_store->end());
	}
	chr::ES_CHR do_owlHasKey(typename owlHasKey::Type c_args, typename owlHasKey::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlHasKey( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2, chr::Logical_var_ground< int > arg3) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3);
		return do_owlHasKey(std::move(c_args), owlHasKey_constraint_store->end());
	}
	chr::ES_CHR do_owlHasKeyCheck(typename owlHasKeyCheck::Type c_args, typename owlHasKeyCheck::Constraint_store_t::iterator c_it);
	chr::ES_CHR owlHasKeyCheck( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var< int > arg2, chr::Logical_var_ground< int > arg3, chr::Logical_var_ground< int > arg4) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4);
		return do_owlHasKeyCheck(std::move(c_args), owlHasKeyCheck_constraint_store->end());
	}
	chr::ES_CHR do_querySuperClassOfUri(typename querySuperClassOfUri::Type c_args, typename querySuperClassOfUri::Constraint_store_t::iterator c_it);
	chr::ES_CHR querySuperClassOfUri( chr::Logical_var_ground< std :: string > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_querySuperClassOfUri(std::move(c_args), querySuperClassOfUri_constraint_store->end());
	}
	chr::ES_CHR do_querySuperClassOfClassUri(typename querySuperClassOfClassUri::Type c_args, typename querySuperClassOfClassUri::Constraint_store_t::iterator c_it);
	chr::ES_CHR querySuperClassOfClassUri( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_querySuperClassOfClassUri(std::move(c_args), querySuperClassOfClassUri_constraint_store->end());
	}
	chr::ES_CHR do_querySubClassOfUri(typename querySubClassOfUri::Type c_args, typename querySubClassOfUri::Constraint_store_t::iterator c_it);
	chr::ES_CHR querySubClassOfUri( chr::Logical_var_ground< std :: string > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_querySubClassOfUri(std::move(c_args), querySubClassOfUri_constraint_store->end());
	}
	chr::ES_CHR do_querySubClassOfClassUri(typename querySubClassOfClassUri::Type c_args, typename querySubClassOfClassUri::Constraint_store_t::iterator c_it);
	chr::ES_CHR querySubClassOfClassUri( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_querySubClassOfClassUri(std::move(c_args), querySubClassOfClassUri_constraint_store->end());
	}
	chr::ES_CHR do_querySuperClassOf(typename querySuperClassOf::Type c_args, typename querySuperClassOf::Constraint_store_t::iterator c_it);
	chr::ES_CHR querySuperClassOf( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_querySuperClassOf(std::move(c_args), querySuperClassOf_constraint_store->end());
	}
	chr::ES_CHR do_querySuperClassOfReal(typename querySuperClassOfReal::Type c_args, typename querySuperClassOfReal::Constraint_store_t::iterator c_it);
	chr::ES_CHR querySuperClassOfReal( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_querySuperClassOfReal(std::move(c_args), querySuperClassOfReal_constraint_store->end());
	}
	chr::ES_CHR do_querySubClassOf(typename querySubClassOf::Type c_args, typename querySubClassOf::Constraint_store_t::iterator c_it);
	chr::ES_CHR querySubClassOf( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_querySubClassOf(std::move(c_args), querySubClassOf_constraint_store->end());
	}
	chr::ES_CHR do_querySubClassOfClass(typename querySubClassOfClass::Type c_args);
	chr::ES_CHR querySubClassOfClass( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_querySubClassOfClass(std::move(c_args));
	}
	chr::ES_CHR do_querySuperClassOfClass(typename querySuperClassOfClass::Type c_args);
	chr::ES_CHR querySuperClassOfClass( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_querySuperClassOfClass(std::move(c_args));
	}
	chr::ES_CHR do_queryClassification(typename queryClassification::Type c_args, typename queryClassification::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryClassification( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_queryClassification(std::move(c_args), queryClassification_constraint_store->end());
	}
	chr::ES_CHR do_queryClassificationReal(typename queryClassificationReal::Type c_args, typename queryClassificationReal::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryClassificationReal( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_queryClassificationReal(std::move(c_args), queryClassificationReal_constraint_store->end());
	}
	chr::ES_CHR do_queryClassificationUri(typename queryClassificationUri::Type c_args, typename queryClassificationUri::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryClassificationUri( chr::Logical_var_ground< std :: string > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_queryClassificationUri(std::move(c_args), queryClassificationUri_constraint_store->end());
	}
	chr::ES_CHR do_queryClassificationTemp(typename queryClassificationTemp::Type c_args, typename queryClassificationTemp::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryClassificationTemp( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_queryClassificationTemp(std::move(c_args), queryClassificationTemp_constraint_store->end());
	}
	chr::ES_CHR do_queryClassificationTempUri(typename queryClassificationTempUri::Type c_args, typename queryClassificationTempUri::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryClassificationTempUri( chr::Logical_var_ground< std :: string > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_queryClassificationTempUri(std::move(c_args), queryClassificationTempUri_constraint_store->end());
	}
	chr::ES_CHR do_queryInstanceURI(typename queryInstanceURI::Type c_args, typename queryInstanceURI::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryInstanceURI( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryInstanceURI(std::move(c_args), queryInstanceURI_constraint_store->end());
	}
	chr::ES_CHR do_queryInstance(typename queryInstance::Type c_args);
	chr::ES_CHR queryInstance( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryInstance(std::move(c_args));
	}
	chr::ES_CHR do_queryInstancesURI(typename queryInstancesURI::Type c_args);
	chr::ES_CHR queryInstancesURI( chr::Logical_var_ground< std :: string > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_queryInstancesURI(std::move(c_args));
	}
	chr::ES_CHR do_queryInstances(typename queryInstances::Type c_args, typename queryInstances::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryInstances( chr::Logical_var< int > arg0, chr::Logical_var_ground< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryInstances(std::move(c_args), queryInstances_constraint_store->end());
	}
	chr::ES_CHR do_queryObjAssertionUri(typename queryObjAssertionUri::Type c_args);
	chr::ES_CHR queryObjAssertionUri( chr::Logical_var_ground< std :: string > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_queryObjAssertionUri(std::move(c_args));
	}
	chr::ES_CHR do_queryObjAssertion(typename queryObjAssertion::Type c_args, typename queryObjAssertion::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryObjAssertion( chr::Logical_var< int > arg0, chr::Logical_var_ground< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryObjAssertion(std::move(c_args), queryObjAssertion_constraint_store->end());
	}
	chr::ES_CHR do_querySubjectByObjectUri(typename querySubjectByObjectUri::Type c_args);
	chr::ES_CHR querySubjectByObjectUri( chr::Logical_var_ground< std :: string > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_querySubjectByObjectUri(std::move(c_args));
	}
	chr::ES_CHR do_querySubjectByObject(typename querySubjectByObject::Type c_args, typename querySubjectByObject::Constraint_store_t::iterator c_it);
	chr::ES_CHR querySubjectByObject( chr::Logical_var< int > arg0, chr::Logical_var_ground< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_querySubjectByObject(std::move(c_args), querySubjectByObject_constraint_store->end());
	}
	chr::ES_CHR do_queryDataAssertionUri(typename queryDataAssertionUri::Type c_args);
	chr::ES_CHR queryDataAssertionUri( chr::Logical_var_ground< std :: string > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_queryDataAssertionUri(std::move(c_args));
	}
	chr::ES_CHR do_queryDataAssertion(typename queryDataAssertion::Type c_args, typename queryDataAssertion::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryDataAssertion( chr::Logical_var< int > arg0, chr::Logical_var_ground< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryDataAssertion(std::move(c_args), queryDataAssertion_constraint_store->end());
	}
	chr::ES_CHR do_queryEngineeringStudentsUri(typename queryEngineeringStudentsUri::Type c_args);
	chr::ES_CHR queryEngineeringStudentsUri( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1, chr::Logical_var_ground< std :: string > arg2, chr::Logical_var_ground< std :: string > arg3, chr::Logical_var_ground< std :: string > arg4) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4);
		return do_queryEngineeringStudentsUri(std::move(c_args));
	}
	chr::ES_CHR do_queryEngineeringStudents(typename queryEngineeringStudents::Type c_args, typename queryEngineeringStudents::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryEngineeringStudents( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var< int > arg2, chr::Logical_var< int > arg3, chr::Logical_var< int > arg4, chr::Logical_var_ground< int > arg5) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4, arg5);
		return do_queryEngineeringStudents(std::move(c_args), queryEngineeringStudents_constraint_store->end());
	}
	chr::ES_CHR do_queryComplexStudentsUri(typename queryComplexStudentsUri::Type c_args);
	chr::ES_CHR queryComplexStudentsUri( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1, chr::Logical_var_ground< std :: string > arg2, chr::Logical_var_ground< std :: string > arg3, chr::Logical_var_ground< std :: string > arg4) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4);
		return do_queryComplexStudentsUri(std::move(c_args));
	}
	chr::ES_CHR do_queryComplexStudents(typename queryComplexStudents::Type c_args, typename queryComplexStudents::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryComplexStudents( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var< int > arg2, chr::Logical_var< int > arg3, chr::Logical_var< int > arg4, chr::Logical_var_ground< int > arg5) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4, arg5);
		return do_queryComplexStudents(std::move(c_args), queryComplexStudents_constraint_store->end());
	}
	chr::ES_CHR do_queryObjAssertionSubjectUri(typename queryObjAssertionSubjectUri::Type c_args);
	chr::ES_CHR queryObjAssertionSubjectUri( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryObjAssertionSubjectUri(std::move(c_args));
	}
	chr::ES_CHR do_queryObjAssertionSubject(typename queryObjAssertionSubject::Type c_args, typename queryObjAssertionSubject::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryObjAssertionSubject( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1, chr::Logical_var_ground< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_queryObjAssertionSubject(std::move(c_args), queryObjAssertionSubject_constraint_store->end());
	}
	chr::ES_CHR do_queryObjAssertionClassUri(typename queryObjAssertionClassUri::Type c_args, typename queryObjAssertionClassUri::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryObjAssertionClassUri( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryObjAssertionClassUri(std::move(c_args), queryObjAssertionClassUri_constraint_store->end());
	}
	chr::ES_CHR do_queryObjAssertionClass(typename queryObjAssertionClass::Type c_args, typename queryObjAssertionClass::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryObjAssertionClass( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryObjAssertionClass(std::move(c_args), queryObjAssertionClass_constraint_store->end());
	}
	chr::ES_CHR do_queryEquivalentClass(typename queryEquivalentClass::Type c_args, typename queryEquivalentClass::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryEquivalentClass( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_queryEquivalentClass(std::move(c_args), queryEquivalentClass_constraint_store->end());
	}
	chr::ES_CHR do_queryEquivalentClassReal(typename queryEquivalentClassReal::Type c_args, typename queryEquivalentClassReal::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryEquivalentClassReal( chr::Logical_var< int > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryEquivalentClassReal(std::move(c_args), queryEquivalentClassReal_constraint_store->end());
	}
	chr::ES_CHR do_res(typename res::Type c_args, typename res::Constraint_store_t::iterator c_it);
	chr::ES_CHR res( chr::Logical_var_ground< std :: string > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_res(std::move(c_args), res_constraint_store->end());
	}
	chr::ES_CHR do_resultRealisation(typename resultRealisation::Type c_args, typename resultRealisation::Constraint_store_t::iterator c_it);
	chr::ES_CHR resultRealisation( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_resultRealisation(std::move(c_args), resultRealisation_constraint_store->end());
	}
	chr::ES_CHR do_classification(typename classification::Type c_args, typename classification::Constraint_store_t::iterator c_it);
	chr::ES_CHR classification() {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++);
		return do_classification(std::move(c_args), classification_constraint_store->end());
	}
	chr::ES_CHR do_resultClassification(typename resultClassification::Type c_args, typename resultClassification::Constraint_store_t::iterator c_it);
	chr::ES_CHR resultClassification( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_resultClassification(std::move(c_args), resultClassification_constraint_store->end());
	}
	chr::ES_CHR do_queryFullUri(typename queryFullUri::Type c_args, typename queryFullUri::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryFullUri( chr::Logical_var< int > arg0) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0);
		return do_queryFullUri(std::move(c_args), queryFullUri_constraint_store->end());
	}
	chr::ES_CHR do_logicalName(typename logicalName::Type c_args, typename logicalName::Constraint_store_t::iterator c_it);
	chr::ES_CHR logicalName( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_logicalName(std::move(c_args), logicalName_constraint_store->end());
	}
	chr::ES_CHR do_realisation(typename realisation::Type c_args, typename realisation::Constraint_store_t::iterator c_it);
	chr::ES_CHR realisation() {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++);
		return do_realisation(std::move(c_args), realisation_constraint_store->end());
	}
	chr::ES_CHR do_queryisMemberOf(typename queryisMemberOf::Type c_args, typename queryisMemberOf::Constraint_store_t::iterator c_it);
	chr::ES_CHR queryisMemberOf() {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++);
		return do_queryisMemberOf(std::move(c_args), queryisMemberOf_constraint_store->end());
	}
	chr::ES_CHR do_ResultVec(typename ResultVec::Type c_args, typename ResultVec::Constraint_store_t::iterator c_it);
	chr::ES_CHR ResultVec( chr::Logical_var_ground< StringSet > arg0, chr::Logical_var_ground< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_ResultVec(std::move(c_args), ResultVec_constraint_store->end());
	}
	chr::ES_CHR do_queryInstancesWithId(typename queryInstancesWithId::Type c_args);
	chr::ES_CHR queryInstancesWithId( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryInstancesWithId(std::move(c_args));
	}
	chr::ES_CHR do_queryObjAssertionWithId(typename queryObjAssertionWithId::Type c_args);
	chr::ES_CHR queryObjAssertionWithId( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryObjAssertionWithId(std::move(c_args));
	}
	chr::ES_CHR do_queryDataAssertionWithId(typename queryDataAssertionWithId::Type c_args);
	chr::ES_CHR queryDataAssertionWithId( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_queryDataAssertionWithId(std::move(c_args));
	}
	chr::ES_CHR do_querySubjectByObjectWithId(typename querySubjectByObjectWithId::Type c_args);
	chr::ES_CHR querySubjectByObjectWithId( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< int > arg1) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1);
		return do_querySubjectByObjectWithId(std::move(c_args));
	}
	chr::ES_CHR do_queryObjAssertionSubjectWithId(typename queryObjAssertionSubjectWithId::Type c_args);
	chr::ES_CHR queryObjAssertionSubjectWithId( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1, chr::Logical_var_ground< int > arg2) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2);
		return do_queryObjAssertionSubjectWithId(std::move(c_args));
	}
	chr::ES_CHR do_queryEngineeringStudentsWithId(typename queryEngineeringStudentsWithId::Type c_args);
	chr::ES_CHR queryEngineeringStudentsWithId( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1, chr::Logical_var_ground< std :: string > arg2, chr::Logical_var_ground< std :: string > arg3, chr::Logical_var_ground< std :: string > arg4, chr::Logical_var_ground< int > arg5) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4, arg5);
		return do_queryEngineeringStudentsWithId(std::move(c_args));
	}
	chr::ES_CHR do_queryComplexStudentsWithId(typename queryComplexStudentsWithId::Type c_args);
	chr::ES_CHR queryComplexStudentsWithId( chr::Logical_var_ground< std :: string > arg0, chr::Logical_var_ground< std :: string > arg1, chr::Logical_var_ground< std :: string > arg2, chr::Logical_var_ground< std :: string > arg3, chr::Logical_var_ground< std :: string > arg4, chr::Logical_var_ground< int > arg5) {
		assert(!chr::failed() && (_ref_use_count >= 1));
		auto c_args = std::make_tuple(next_free_constraint_id++, arg0, arg1, arg2, arg3, arg4, arg5);
		return do_queryComplexStudentsWithId(std::move(c_args));
	}
};
#endif // OWL2__GUARD
